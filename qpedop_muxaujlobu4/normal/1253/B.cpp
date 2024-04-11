#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[1000001];
bool res=true;
int Index[100000];
void NewDay(int l){
for(int i=0;i<l;++i){
    if(a[Index[i]]==1)res=false;
    a[Index[i]]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>C;
    C.reserve(50001);
    int NowLong=0;
    int NowLongInd=0,c1=0,c2=0,c0=1000000;
    for(int i=0;i<1000001;++i)
        a[i]=0;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        ++NowLong;
        //cout<<i<<endl;
        //if(i==2)cout<<tmp<<" "<<a[tmp]<<endl;
        if(tmp>0){
            if(a[tmp]==0){
                --c0;
                ++c1;
                //cout<<" "<<a[1]<<endl;
                a[tmp]=1;
                Index[NowLongInd++]=tmp;
            }
            else {
                if(a[tmp]==2){
                    //cout<<i<<endl;
                    //cout<<Index[0]<<" ";
                        //cout<<a[Index[0]]<<" ";
                    NewDay(NowLongInd);
                    C.push_back(NowLong-1);
                    //for(int i1=0;i1<NowLongInd;++i1)
                        //cout<<Index[0]<<" ";
                        //out<<a[Index[0]];
                    //cout<<endl;
                    Index[0]=tmp;
                    a[tmp]=1;
                    NowLong=1;
                    NowLongInd=1;
                    c0=999999;
                    c2=0;
                    c1=1;

                }
                else{
                    //cout<<i<<endl;
                    res=false;
                }
            }
        }
        else{
            tmp=-tmp;
            //cout<<" "<<a[1]<<endl;
            if(a[tmp]==1){
                a[tmp]=2;
                --c1;
                ++c2;
            }
            else{
                //cout<<i<<endl;
                res=false;
            }
        }
        if(!res)break;
        if(i==n-1||c1==0){
            c1=c2=0;
            c0=1000000;
            NewDay(NowLongInd);
            C.push_back(NowLong);
            NowLongInd=0;
            NowLong=0;
        }
    }

    if(!res){
        cout<<-1;
    }
    else{
        cout<<(int)C.size()<<"\n";
        for(int i=0;i<(int)C.size();++i)
            cout<<C[i]<<" ";
    }
    return 0;
}