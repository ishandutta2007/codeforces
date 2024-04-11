#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[100000];

int main(){
    ios_base::sync_with_stdio(false);
    int t,n;
    cin >>t;
    for(int i=0;i<t;++i){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        bool ok=false;
        int ct=0;
        int r;
        bool res=true;
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            a[i]-=tmp;
            if(a[i]>0)res=false;
            if(a[i]!=0&&!ok){
                ++ct;
                r=a[i];
                ok=true;
            }
            else{
                if(a[i]==0&&ok){
                    ok=false;
                }
                else{
                    if(a[i]!=0&&ok){
                        if(a[i]!=r){
                            res=false;
                        }
                    }
                }
            }
            if(ct>1)res=false;

        }
        if(res)cout<<"YES\n";
            else cout<<"NO\n";
    }
    return 0;
}