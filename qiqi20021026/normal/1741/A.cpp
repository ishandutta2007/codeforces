#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    vector<int> f(1000);
    f['S']=-1; f['M']=0; f['L']=1;
    while (T--){
        string a,b; cin>>a>>b;
        if (a==b){
            cout<<"=\n";
            continue;
        }
        cout<<((int)a.size()*f[*a.rbegin()]<(int)b.size()*f[*b.rbegin()]?"<":">")<<'\n';
    }
}