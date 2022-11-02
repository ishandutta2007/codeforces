#include <iostream>
#include <string>
using namespace std;
int main() {
    int n,sit=0,stand;
    cin>>n;
    string s;
    cin>>s;
    for(char c : s){
        sit+=(c=='x');
    }
    stand=n-sit;
    if(sit==n/2){
        cout<<0<<endl<<s<<endl;
        return 0;
    }
    else if(sit>n/2){
        int diff=(sit-stand)/2;
        cout<<diff<<endl;
        for(int i =0;i<n;i++){
            if(diff>0&&s[i]=='x'){
                s[i]='X';
                diff--;
            }
        }
        cout<<s<<endl;
    }
    else {
        int diff=(stand-sit)/2;
        cout<<diff<<endl;
        for(int i =0;i<n;i++){
            if(diff>0&&s[i]=='X'){
                s[i]='x';
                diff--;
            }
        }
        cout<<s<<endl;
    }
}