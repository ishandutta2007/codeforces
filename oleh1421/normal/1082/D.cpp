#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[502];
int main()
{
    //int n;cin>>n;
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>u;
    vector<int>v;
    int sum=0;
    for (int i=1;i<=n;i++){
        if (a[i]==1) u.push_back(i);
        else v.push_back(i);
        sum+=a[i];
    }
    if (sum<n+n-2){
        cout<<"NO";
        return 0;
    }
    if (u.size()==0){
        cout<<"YES "<<n-1<<endl;
        cout<<n-1<<endl;

        for (int i=1;i<v.size();i++){
            cout<<v[i-1]<<" "<<v[i]<<endl;
        }
        return 0;
    }
    if (u.size()==1){
        cout<<"YES "<<n-1<<endl;
        cout<<n-1<<endl;
        cout<<u[0]<<" "<<v[0]<<endl;
        for (int i=1;i<v.size();i++){
            cout<<v[i-1]<<" "<<v[i]<<endl;
        }
        return 0;
    }
    vector<pair<int,int> >q;
    q.push_back({u[0],v[0]});
    q.push_back({v.back(),u[1]});
    a[v[0]]--;
    a[v.back()]--;
    for (int i=1;i<v.size();i++){
        q.push_back({v[i-1],v[i]});
        a[v[i-1]]--;
        a[v[i]]--;
    }
    for (int i=2;i<u.size();i++){
        bool ok=true;
        for (int j=0;j<v.size();j++){
            if (a[v[j]]>0){
                ok=false;
                a[v[j]]--;
                q.push_back({v[j],u[i]});
                break;
            }
        }
        if (ok){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES "<<v.size()+1<<endl;
    cout<<n-1<<endl;
    for (auto cur:q){
        cout<<cur.first<<" "<<cur.second<<endl;
    }
   return 0;
}