#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
    int n;
    cin>>n;
    char a[20]={NULL};
    cin>>a;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]>'1'){
            if(a[i]=='4'){
                v.pb(3);
                v.pb(2);
                v.pb(2);
            }
            else if(a[i]=='8'){
                v.pb(2);
                v.pb(2);
                v.pb(2);
                v.pb(7);
            }
            else if(a[i]=='9'){
                v.pb(7);
                v.pb(3);
                v.pb(3);
                v.pb(2);
            }
            else if(a[i]=='6'){
                v.pb(5);
                v.pb(3);
            }
            else{
                v.pb(a[i]-'0');
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
}