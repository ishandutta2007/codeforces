#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int n;
vector<int> v;
int main(){
    cin>>n;
    cin>>s;
    bool new_cnt=true;
    int cnt=0, temp=0;
    for(int i=0; i<n; i++){
        if(s.at(i)=='B'){
            if(new_cnt){
                cnt++;
                temp++;
                new_cnt=false;
            }else{
                temp++;
            }
        }else{
            if(temp==0){
                continue;
            }else{
                v.push_back(temp);
                temp=0;
                new_cnt=true;
            }
        }
    }
    if(!new_cnt){
        v.push_back(temp);
    }
    cout<<cnt<<endl;
    for(int i:v){
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}