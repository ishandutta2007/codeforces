#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;
#define double long double
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
double distance(pair<double,double> p1,pair<double,double> p2)
{
    double d=fabs(p1.first-p2.first)+fabs(p1.second-p2.second);
    return d;
}
double dist2(pair<double,double> p1,pair<double,double> p2)
{
    double d=(double)sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
    return d;
}
int main()
{
    double dista=LLONG_MAX;
    int a,b,c;
    scanf("%i %i %i",&a,&b,&c);
    int x1,y1,x2,y2;
    scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
    pair<double,double> A=make_pair(x1,y1),B=make_pair(x2,y2);
    vector<pair<double,double> > pointsA,pointsB;
    pointsA.pb(A);
    pointsB.pb(B);
    double xx1=-1*(ll)((ll)b*y1+c);
    xx1/=(double)a;
    pointsA.pb({xx1,y1});
    double yy1=-1*(ll)((ll)a*x1+c);
    yy1/=(double)b;
    pointsA.pb({x1,yy1});
    double xx2=-1*(ll)((ll)b*y2+c);
    xx2/=(double)a;
    pointsB.pb({xx2,y2});
    double yy2=-1*(ll)((ll)a*x2+c);
    yy2/=(double)b;
    pointsB.pb({x2,yy2});
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //printf("%lf %lf   %lf %lf\n",pointsA[i].first,pointsA[i].second,pointsB[j].first,pointsB[j].second);
            double d=distance(A,pointsA[i])+distance(B,pointsB[j]);
            if(i>0&&j>0)
            {
                d+=dist2(pointsA[i],pointsB[j]);
            }
            else
            {
                d+=distance(pointsA[i],pointsB[j]);
            }
            dista=min(dista,d);
        }
    }
    cout << setprecision(50) << dista << "\n";
    return 0;
}