#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <string>
using namespace std;
long long a[4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    long long n,k;
    cin>>n>>k;
    cin>>s;
    vector<char>b(k);
    for(int i=0;i<k;++i)cin>>b[i];
    long long res=0,tprs=0;
    bool ok=false;
    for(int i=0;i<n;++i){
        ok=false;
       for(int j=0;j<k;++j)
           if(b[j]==s[i]){
            ok=true;
            break;
            }
        if(ok){
            ++tprs;
        }
        else{
            res+=tprs*(tprs+1)/2;
            tprs=0;
        }
    }
    if(ok)res+=tprs*(tprs+1)/2;
    cout<<res;
    return 0;
}