// https://codeforces.com/contest/1305/submission/72350668
#include<bits/stdc++.h>
using namespace std;
#define tez ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
int main(){
    tez;
    string s;
    cin>>s;
    vector<int> open;
    vector<int> close;
    vector<int> out;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            open.push_back(i);
        }
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==')'){
            close.push_back(i);
        }
    }
    int o=0;
    while(o<close.size() && o<open.size() && open[o]<close[o]){
        out.push_back(open[o]);
        out.push_back(close[o]);
        o++;
    }
    if(out.empty()){
        cout<<"0";
    }
    else{
        cout<<"1\n";
        cout<<out.size()<<"\n";
        sort(out.begin(),out.end());
        for(auto it : out){
            cout<<(it+1)<<" ";
        }
    }
    return 0;
}