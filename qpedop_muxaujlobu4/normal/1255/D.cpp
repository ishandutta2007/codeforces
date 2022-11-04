#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[101][101];
char b[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    int T,n;
    cin>>T;
    for(int i=0;i<T;++i){
        int r,c,k;
        cin>>r>>c>>k;
        int s=0;
        for(int j=1;j<=r;++j)
            for(int j1=1;j1<=c;++j1){
                char tmp;
                cin>>tmp;
                if (tmp=='R'){
                    ++s;
                    a[j][j1]=1;
                }
                else a[j][j1]=0;
            }
        int minpoint=s/k,ctmax=s%k,tmp=0;
        int ctmin=k-ctmax;
        char kur='a';
        for(int j=1;j<=r;++j){
            if(j%2==0){
                for(int j1=1;j1<=c;++j1){
                    b[j][j1]=kur;
                    if(a[j][j1]==1)++tmp;
                    if(tmp==minpoint+1||tmp==minpoint&&ctmax==0){
                        tmp=0;
                        if(ctmax!=0)--ctmax;
                        else --ctmin;
                        if(ctmax!=0||ctmin!=0){
                            if(kur=='z')kur='A';
                            else{
                                if(kur=='Z')kur='0';
                                else ++kur;
                            }
                        }
                    }
                }
            }
            else {
                 for(int j1=c;j1>0;--j1){
                    b[j][j1]=kur;
                    if(a[j][j1]==1)++tmp;
                    if(tmp==minpoint+1||tmp==minpoint&&ctmax==0){
                        tmp=0;
                        if(ctmax!=0)--ctmax;
                        else --ctmin;
                        if(ctmax!=0||ctmin!=0){
                            if(kur=='z')kur='A';
                            else{
                                if(kur=='Z')kur='0';
                                else ++kur;
                            }
                        }
                    }
                }
            }
        }
        for(int j=1;j<=r;++j)
        {
            for(int j1=1;j1<=c;++j1)
                cout<<b[j][j1];
            cout<<endl;
        }
    }
    return 0;
}