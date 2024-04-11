#include <iostream>
using namespace std;
typedef pair<int, int> pii;
int y[1050];
int n;
int main(){
    cin>>n;
    if(n==3){
        cin>>y[1]>>y[2]>>y[3];
        if(y[2]-y[1]==y[3]-y[2]) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }else if(n==4){
        cin>>y[1]>>y[2]>>y[3]>>y[4];
        if(y[4]-y[3]==y[3]-y[2]&&y[3]-y[2]==y[2]-y[1]) cout<<"No"<<endl;//1234
        else{
            if(y[2]-y[1]==y[3]-y[2]){//123
                cout<<"Yes"<<endl;
                return 0;
            }
            if(y[4]-y[2]==2*(y[2]-y[1])){//124
                cout<<"Yes"<<endl;
                return 0;
            }
            if(2*(y[4]-y[3])==y[3]-y[1]){//134
                cout<<"Yes"<<endl;
                return 0;
            }
            if(y[4]-y[3]==y[3]-y[2]){//234
                cout<<"Yes"<<endl;
                return 0;
            }
            int k1=y[2]-y[1], k2=y[4]-y[3];
            if(k1==k2) cout<<"Yes"<<endl;
            else{
                k1=y[3]-y[1], k2=y[4]-y[2];
                if(k1==k2) cout<<"Yes"<<endl;
                else{
                    k1=y[4]-y[1], k2=y[3]-y[2];
                    if(k1==3*k2) cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }
            }
        }
    }else{
        int cur1, cur2;
        pii k1, k2;
        cur1=cur2=0;
        cin>>y[1]>>y[2]>>y[3]>>y[4]>>y[5];
        if(y[4]-y[3]==y[3]-y[2]&&y[3]-y[2]==y[2]-y[1]){//1234
            if(y[5]-y[4]==y[4]-y[3]){
                cur1=5;
                k2=k1=make_pair(y[4]-y[3], 1);
            }else{
                cur1=4;
                cur2=5;
                k1=k2=make_pair(y[2]-y[1], 1);
            }
        }else if(y[2]-y[1]==y[3]-y[2]&&2*(y[3]-y[2])==y[5]-y[3]){//1235, 4
            cur1=5;
            cur2=4;
            k1=k2=make_pair(y[2]-y[1], 1);
        }else if(y[5]-y[4]==y[2]-y[1]&&2*(y[5]-y[4])==y[4]-y[2]){//1245, 3
            cur1=5;
            cur2=3;
            k1=k2=make_pair(y[2]-y[1], 1);
        }else if(y[5]-y[4]==y[4]-y[3]&&2*(y[4]-y[3])==y[3]-y[1]){//1345, 2
            cur1=5;
            cur2=2;
            k1=k2=make_pair(y[5]-y[4], 1);
        }else if(y[5]-y[4]==y[4]-y[3]&&y[4]-y[3]==y[3]-y[2]){//2345, 1
            cur1=5;
            cur2=1;
            k1=k2=make_pair(y[5]-y[4], 1);
        }else{
            k1=make_pair(y[2]-y[1], 1), k2=make_pair(y[4]-y[3], 1);
            if(k1==k2){
                if(y[5]-y[2]==3*k1.first){//125, 34
                    cur1=5;
                    cur2=4;
                }else if(y[5]-y[4]==k2.first){//12, 345
                    cur1=2;
                    cur2=5;
                }else goto label1;
            }
            else{
                label1:
                k1=make_pair(y[3]-y[1], 2), k2=make_pair(y[4]-y[2], 2);
                if(k1==k2){
                    if(2*(y[5]-y[4])==k1.first){//13, 245
                        cur1=3;
                        cur2=5;
                    }else if(y[5]-y[3]==k1.first){//135, 24
                        cur1=5;
                        cur2=4;
                    }else goto label2;
                }
                else{
                    label2:
                    k1=make_pair(y[4]-y[1], 3), k2=make_pair(y[3]-y[2], 1);
                    if(k1.first==3*k2.first){
                        if(3*(y[5]-y[4])==k1.first){//145, 23
                            cur1=5;
                            cur2=3;
                            k1=k2;
                        }else if(y[5]-y[3]==2*k2.first){//14, 235
                            cur2=5;
                            cur1=4;
                            k1=k2;
                        }else goto label3;
                    }
                    else{
                        label3:
                        if(y[2]-y[1]==y[3]-y[2]&&y[5]-y[4]==y[3]-y[2]){//123, 45
                            k2=k1=make_pair(y[2]-y[1], 1);
                            cur1=3;
                            cur2=5;
                        }else if(y[4]-y[2]==2*(y[2]-y[1])&&y[5]-y[3]==y[4]-y[2]){//124, 35
                            k2=k1=make_pair(y[2]-y[1], 1);
                            cur1=4;
                            cur2=5;
                        }else if(y[3]-y[2]==y[4]-y[3]&&y[5]-y[1]==4*(y[4]-y[3])){//234, 15
                            k2=k1=make_pair(y[3]-y[2], 1);
                            cur1=4;
                            cur2=5;
                        }else if(y[3]-y[1]==2*(y[4]-y[3])&&y[5]-y[2]==3*(y[4]-y[3])){//134, 25
                            k2=k1=make_pair(y[4]-y[3], 1);
                            cur1=4;
                            cur2=5;
                        }else{
                            cout<<"No"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
        for(int i=6; i<=n; i++){
            cin>>y[i];
            if((y[i]-y[cur1])*k1.second==(i-cur1)*k1.first){
                cur1=i;
                continue;
            }else if(cur2){
                if((y[i]-y[cur2])*k2.second==(i-cur2)*k1.first){
                    cur2=i;
                    continue;
                }
                cout<<"No"<<endl;
                return 0;
            }else{
                cur2=i;
                k2=k1;
            }
        }
        if(cur2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}