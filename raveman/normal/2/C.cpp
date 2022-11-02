#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

double x[3],y[3],r[3];

double X1,Y1,R1;
double X2,Y2,R2;

void buildC(int p1,int p2){
 
    double r2 = r[p2],r1 = r[p1];


    double x2 = r2*r2-r1*r1;
    double x1 = -2*x[p1]*r2*r2 + 2 * x[p2]*r1*r1;
    double x0 = r2*r2*x[p1]*x[p1] - r1*r1*x[p2]*x[p2];

    x1/=x2,x0/=x2;

    double y2 = r2*r2-r1*r1;
    double y1 = -2*y[p1]*r2*r2 + 2 * y[p2]*r1*r1;
    double y0 = r2*r2*y[p1]*y[p1] - r1*r1*y[p2]*y[p2];

    y1/=y2,y0/=y2;

    X1 = -x1/2;
    Y1 = -y1/2;

    R1 = sqrt(-x0-y0+x1*x1/4+y1*y1/4);
}

double ddd = 1e100;
double resX=0,resY=0;
double dd[3];

void tr(double X,double Y){
    REP(i,3) dd[i]=hypot(X-x[i],Y-y[i]);
    double k = dd[0]/r[0];
    REP(i,3){
        double kk = dd[i]/r[i];

        if(fabs(k-kk)>1e-5)
            return;
    }
    if(k<ddd){
        ddd=k;
        resX=X,
            resY=Y;
    }
}

double a[2][3];

double det(double a11,double a12,double a21,double a22){return a11*a22-a12*a21;}

void swaP(int p1,int p2){
    swap(x[p1],x[p2]);
    swap(y[p1],y[p2]);
    swap(r[p1],r[p2]);
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    REP(i,3) cin>>x[i]>>y[i]>>r[i];

    if(fabs(r[0]-r[1])<1e-5 && fabs(r[0]-r[2])<1e-5){
        double t1x = (x[0]+x[1])/2;
        double t1y = (y[0]+y[1])/2;

        double t2x = (x[0]+x[2])/2;
        double t2y = (y[0]+y[2])/2;

        double dx1 = x[1]-x[0];
        double dy1 = y[1]-y[0];
        swap(dx1,dy1),dx1*=(-1);

        double dx2 = x[2]-x[0];
        double dy2 = y[2]-y[0];
        swap(dx2,dy2),dx2*=(-1);

        a[0][0]=dx1,a[0][1]=-dx2,a[0][2]=t2x-t1x;
        a[1][0]=dy1,a[1][1]=-dy2,a[1][2]=t2y-t1y;

        double t = det(a[0][2],a[0][1],a[1][2],a[1][1])/
            det(a[0][0],a[0][1],a[1][0],a[1][1]);

        double xx = t1x + t * dx1;
        double yy = t1y + t * dy1;

        printf("%.5lf %.5lf\n",xx,yy);

    }else{
        if(fabs(r[0]-r[1])<1e-5) swaP(0,2);
        if(fabs(r[0]-r[2])<1e-5) swaP(0,1);

        buildC(0,1);
        X2=X1,Y2=Y1,R2=R1;
        buildC(0,2);

        double A = -2*X1+2*X2;
        double B = -2*Y1+2*Y2;
        double C = R1*R1-R2*R2 - X1*X1-Y1*Y1+X2*X2+Y2*Y2;

        if(fabs(A)>1e-8){
            B=(-B)/A;
            C=C/A;

            double a1 = 1+B*B;
            double a2 = -2*Y1+2*B*(C-X1);
            double a3 = (C-X1)*(C-X1)+Y1*Y1-R1*R1;

            double D = a2*a2-4*a1*a3;
            if(D<0) D=0;
            D=sqrt(D);

            double yy = (-a2 - D)/2/a1;

            tr(B*yy+C,yy);

            yy = (-a2 + D)/2/a1;

            tr(B*yy+C,yy);
        }else{
            double Y = C/B;
            double D = R1*R1-(Y-Y1)*(Y-Y1);
            if(D<0) D=0;
            D=sqrt(D);
            double X = D + X1;
            tr(X,Y);
            X = -D + X1;
            tr(X,Y);                
        }
    }

    if(ddd<1e50)
        printf("%.5lf %.5lf\n",resX,resY);

    return 0;
}