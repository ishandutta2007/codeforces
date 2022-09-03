#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string,int> m;
string tmp;
int n;
int main()
{
cin>>n;
while(n--)
{
cin>>tmp;
if(m[tmp])cout<<tmp<<m[tmp]<<endl;else cout<<"OK\n";
m[tmp]++;
}
return 0;
}