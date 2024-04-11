#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
char tmp[1000];
vector<string> path;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%s",tmp);
        if(tmp[0]=='c'){
            scanf("%s",tmp);
            int i=0;
            if(tmp[0]=='/'){
                i++;
                path.clear();
            }
            string r;
            for(;tmp[i];i++){
                if(tmp[i]=='/'){
                    if(r!=""){
                        if(r==".."){
                            path.pop_back();
                        }else{
                            path.push_back(r);
                        }
                    }
                    r="";
                }else{
                    r+=tmp[i];
                }
            }
            if(r!=""){
                if(r==".."){
                    path.pop_back();
                }else{
                    path.push_back(r);
                }
            }
            r="";
        }else{
            printf("/");
            for(int i=0;i<path.size();i++)printf("%s/",path[i].c_str());
            puts("");
        }
    }
}