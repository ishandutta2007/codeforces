#include <iostream>
#include <string.h>
using namespace std;
string a[102];
int n,m;
int main(){
cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(a[i][j]=='-'){cout<<'-';}
else if((i+j)&1)cout<<'B';
else cout<<'W';
}
cout<<endl;
}
return 0;
}