#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;

std::vector<int> A;
std::vector<int> B;

std::vector<int> X;
std::vector<int> Y;

int n;
void rek(int x1, int x2, int y1, int y2, int l, int r)
{

    int xh = (x1+x2)/2;
    int yh = (y1+y2)/2;
    int n1,n2,n3,n4;
    n1=0;
    n2=0;
    n3=0;
    n4=0;


    if(l==r){return;}

//cout << l << " " << r << " " << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
int c;

    for(c=l;c<=r;c++){B[c] = A[c];}

    ll xt,yt;
    ll lt=l;
    ll k=0;
    for(c=l;c<=r;c++)
    {
        xt=X[B[c]];
        yt=Y[B[c]];
        if(xt <= xh && yt <= yh){

            n1++;
            lt++;
            A[l+k]=B[c];
            k++;

        }

    }




    for(c=l;c<=r;c++)
    {
        xt=X[B[c]];
        yt=Y[B[c]];
        if(xt > xh && yt <= yh){

            n2++;
            lt++;
            A[l+k]=B[c];
            k++;

        }

    }




    for(c=l;c<=r;c++)
    {
        xt=X[B[c]];
        yt=Y[B[c]];
        if(xt > xh && yt > yh){

            n3++;
            lt++;
            A[l+k]=B[c];
            k++;

        }

    }



    for(c=l;c<=r;c++)
    {
        xt=X[B[c]];
        yt=Y[B[c]];
        if(xt <= xh && yt > yh){

            n4++;
            lt++;
            A[l+k]=B[c];
            k++;

        }

    }



    if(n1!=0){rek(x1,xh,y1,yh,l,l+n1-1);}
    if(n2!=0){rek(xh+1,x2,y1,yh,l+n1,l+n1+n2-1);}
    if(n3!=0){rek(xh+1,x2,yh+1,y2,l+n1+n2,l+n1+n2+n3-1);}
    if(n4!=0){rek(x1,xh,yh+1,y2,l+n1+n2+n3,l+n1+n2+n3+n4-1);}

    //for(c=0;c<n;c++){cout << A[c] << " ";}cout << "\n";

    return;




}

int main()
{
    ll c1,c2,c3,c4,c5,c6;

    ll T;
    int a,b;
    scanf("%d" , &n);

    for(c1=0;c1<n;c1++)
    {

        scanf("%d %d" , &a,&b);
        X.push_back(a);
        Y.push_back(b);
        A.push_back(c1);
        B.push_back(c1);

    }

    rek(0,1000000,0,1000000,0,n-1);
    for(c1=0;c1<n-1;c1++)
    {


        printf("%d " , A[c1]+1);

    }
printf("%d\n" , A[n-1]+1);
    return 0;
}