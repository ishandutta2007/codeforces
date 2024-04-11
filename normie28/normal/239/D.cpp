#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int > pp;
 
int const N=1e6+10,oo=1e9;
int mod=oo+7;
ll const OO=1e18;
 
int n,h;
pp aa[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>h;
    for(int i=0;i<n;i++)cin>>aa[i].first,aa[i].second=i;
    if(n==2){
        cout<<0<<endl;
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    sort(aa,aa+n);
    int an=aa[n-1].first+aa[n-2].first-aa[0].first-aa[1].first,wh=n+1;
    for(int i=n-2;i>=0;i--){
        int mx,mn;
        if(i==n-2){
            mx=aa[n-1].first+aa[n-2].first+h;
            if(i==1){
                mn=aa[0].first+aa[1].first;
            }else{
                mn=aa[0].first+aa[1].first+h;
                mn=min(mn,aa[0].first+aa[n-2].first);
                if(2!=n-2){
                    mn=min(mn,aa[1].first+aa[2].first);
                    mn=min(mn,aa[0].first+aa[2].first);
                }
            }
        }else{
            mx=max(aa[n-1].first+aa[n-2].first,aa[n-1].first+aa[i].first+h);
            if(i==1){
                mn=aa[0].first+aa[1].first;
            }else if(i==0){
                mn=min(aa[0].first+aa[1].first+h,aa[1].first+aa[2].first);
            }else{
                mn=aa[0].first+aa[1].first+h;
                mn=min(mn,aa[0].first+aa[i].first);
                if(2!=i){
                    mn=min(mn,aa[1].first+aa[2].first);
                    mn=min(mn,aa[0].first+aa[2].first);
                }
            }            
        }
        if(mx-mn<an){
            an=mx-mn;
            wh=i;
        }
    }
    if(wh==n+1){
        cout<<an<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<' ';
        }
        cout<<endl;
        return 0;
    }
    cout<<an<<endl;
    string res;
    for(int i=0;i<n;i++) res+='2';
    res[aa[0].second]='1';
    res[aa[wh].second]='1';
    for(auto e:res) cout<<e<<' ';
}