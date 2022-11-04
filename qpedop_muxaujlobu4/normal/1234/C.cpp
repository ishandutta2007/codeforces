#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int b[200002][2];
struct MC{
int x;
int y;
};
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>n;
        for(int j=0;j<n;++j){
            char tmp;
            cin>>tmp;
            b[j][0]=tmp-'0';
        }
        for(int j=0;j<n;++j){
            char tmp;
            cin>>tmp;
            b[j][1]=tmp-'0';
        }
        MC tmp;
        tmp.x=0;
        tmp.y=0;
        for(int j=0;j<n;++j){
           // cin>>b[j][0]>>b[j][1];
            if(b[j][0]<=2)b[j][0]=0;else b[j][0]=1;
            if(b[j][1]<=2)b[j][1]=0;else b[j][1]=1;
            if(tmp.x<j)continue;
            if(j==0)
            {
                if(b[0][0]==0)tmp.x=1;
                else{
                    if(b[0][1]==1){
                        tmp.x=1;
                        tmp.y=1;
                    }
                }
            }
            else
            {
                if(tmp.y==1){
                   if(b[j][1]==0){
                    ++tmp.x;
                   }
                   else{
                    if(b[j][0]==1){
                        ++tmp.x;
                        tmp.y=0;
                    }
                   }
                }
                else{
                    if(b[j][0]==0){
                        ++tmp.x;
                    }
                    else{
                        if(b[j][1]==1){
                            ++tmp.x;
                            tmp.y=1;
                        }
                    }
                }
            }
        }
        if(tmp.x==n&&tmp.y==1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}