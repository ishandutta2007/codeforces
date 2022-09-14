#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
#define double long double
typedef long long ll;

const int N=2010;
const double mod=1000000007;



double xl[N];
double xr[N];
double y[N];
double inf=1e18+1.0;
double eps=1e-10;
int L=0;
int R=0;
vector<double>check;
int n;
double intr(pair<double,double>a,pair<double,double>b){
    return (a.second-b.second)/(b.first-a.first);
}
bool to_erase(pair<double,double>a,pair<double,double>b,pair<double,double>c){
    return (intr(a,c)<=intr(a,b));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for (int i=0;i<n;i++){
        xl[i+1]=v[i].second.first;
        xr[i+1]=v[i].second.second;
        y[i+1]=v[i].first;
    }
    vector<pair<double,double> >u;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;j++){
            if (abs(y[i]-y[j])<eps) continue;
            ///
            if (y[i]>y[j]){
//            cout<<xl[j]-xl[i]<<" "<<xr[j]-xl[i]<<endl;
                u.push_back({(xl[j]-xl[i])/(y[i]-y[j]),(xr[j]-xl[i])/(y[i]-y[j])-eps});
                u.push_back({(xl[j]-xr[i])/(y[i]-y[j])+eps,(xr[j]-xr[i])/(y[i]-y[j])});
            } else {
                u.push_back({(xr[j]-xl[i])/(y[i]-y[j])+eps,(xl[j]-xl[i])/(y[i]-y[j])});
                u.push_back({(xr[j]-xr[i])/(y[i]-y[j]),(xl[j]-xr[i])/(y[i]-y[j])-eps});
            }
//            k>=(xl[i]-xl[j])/(y[i]-y[j])
//            k<=(xr[j]-xl[i])/(y[i]-y[j]);
        }
    }
    vector<pair<double,double> >mrg;
    sort(u.begin(),u.end());
    if (!u.empty()){
        double L=u[0].first;
        double R=u[0].second;

//        cout<<L<<" "<<R<<endl;
        for (int i=1;i<u.size();i++){
//            cout<<u[i].first<<" "<<u[i].second<<endl;
            if (u[i].first<R+eps) R=max(R,u[i].second);
            else {
                mrg.push_back({L,R});
                L=u[i].first;
                R=u[i].second;
            }
        }
        mrg.push_back({L,R});
    }

    for (auto cur:mrg){
        check.push_back(cur.first);
        check.push_back(cur.second);
    }
    for (int i=1;i<mrg.size();i++){
        check.push_back((mrg[i].first+mrg[i-1].second)/2.0);
    }
    if (check.empty()) check.push_back(0.0);
    double res=inf;
    vector<pair<double,double> >vec1;
    for (int i=n;i>=1;i--){
        if (vec1.size()>=1 && vec1.back().first==y[i]){
            if (vec1.back().second<xr[i]) vec1.pop_back();
            else continue;
        }
//        cout<<i<<endl;
        while (vec1.size()>=2 && to_erase(vec1[vec1.size()-2],vec1.back(),{y[i],xr[i]})){
            vec1.pop_back();
        }
        vec1.push_back({y[i],xr[i]});
    }


    vector<pair<double,double> >vec2;
    for (int i=1;i<=n;i++){
        if (vec2.size()>=1 && vec2.back().first==(-y[i])){
            if (vec2.back().second<(-xl[i])) vec2.pop_back();
            else continue;
        }
//        cout<<i<<endl;
        while (vec2.size()>=2 && to_erase(vec2[vec2.size()-2],vec2.back(),{-y[i],-xl[i]})){
            vec2.pop_back();
        }
        vec2.push_back({-y[i],-xl[i]});
    }
    sort(check.begin(),check.end());
    for (double k:check){
        double mn=inf;
        double mx=-inf;
//        while (vec1.size()>=2){
//            auto cur=vec1.back();
//            double val=cur.first*k+cur.second;
//            vec1.pop_back();
//            auto cur1=vec1.back();
//            double val1=cur1.first*k+cur1.second;
//            if (val>val1){
//                mx=val;
//                vec1.push_back(cur);
//                break;
//            }
//        }
//        mx=max(mx,vec1.back().first*k+vec1.back().second);
        for (auto cur:vec1){
            mx=max(mx,(cur.first*k+cur.second));
        }
        for (auto cur:vec2){
            mn=min(mn,-(cur.first*k+cur.second));
        }
//        for (int i=1;i<=n;i++){
////            mx=max(mx,xr[i]+y[i]*k);
//            mn=min(mn,xl[i]+y[i]*k);
//        }
        res=min(res,mx-mn);
//        cout<<k<<endl;

    }
    cout<<setprecision(10)<<fixed<<res<<endl;
    return 0;
}