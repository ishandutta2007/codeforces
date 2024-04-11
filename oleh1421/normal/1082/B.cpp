#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100002];
int main()
{
    int n;cin>>n;
    string s;cin>>s;
    vector<int>v;
    int cnt=1;
    for (int i=1;i<n;i++){
        if (s[i]==s[i-1]) cnt++;
        else {
            v.push_back(cnt);
            cnt=1;
        }
    }
    v.push_back(cnt);
    if (s[0]=='G'){
        if (v.size()==1){
            cout<<n;
            return 0;
        }
        int maxx=0;
        for (int i=0;i<v.size();i+=2){
            maxx=max(maxx,v[i]+(v.size()>2));
        }
        for (int i=2;i<v.size();i+=2){
            if (v[i-1]==1 && ((i+2)<v.size() || i-4>=0)) maxx=max(maxx,v[i]+v[i-2]+1);
            if (v[i-1]==1) maxx=max(maxx,v[i]+v[i-2]);
        }
        cout<<maxx<<endl;
    } else {
        if (v.size()==1){
            cout<<0;
            return 0;
        }
        int maxx=0;
        for (int i=1;i<v.size();i+=2){
            maxx=max(maxx,v[i]+(v.size()>3));
        }
        for (int i=3;i<v.size();i+=2){
            if (v[i-1]==1 && ((i+2)<v.size() || i-4>0)) maxx=max(maxx,v[i]+v[i-2]+1);
            if (v[i-1]==1) maxx=max(maxx,v[i]+v[i-2]);
        }
        cout<<maxx<<endl;
    }
   return 0;
}
/*
4
GSGS
*/