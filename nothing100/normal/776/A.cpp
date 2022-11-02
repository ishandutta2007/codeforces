#include<bits/stdc++.h>
#define LL long long
#define mo 1594323
using namespace std;
string s[2],tmp[2];
int n;
int main(){
    cin>>s[0]>>s[1];
    scanf("%d",&n);
    cout<<s[0]<<" "<<s[1]<<endl;
    for (int i=0;i<n;i++){
        cin>>tmp[0]>>tmp[1];
        if(s[0]==tmp[0]) s[0]=tmp[1];
        else s[1]=tmp[1];
        cout<<s[0]<<" "<<s[1]<<endl;
    }
    return 0;
}