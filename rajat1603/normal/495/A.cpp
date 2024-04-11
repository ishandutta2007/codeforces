#include <bits/stdc++.h>
using namespace std;
 
int p[]={2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
 
int main(){
 
    char a[3];
    cin>>a;
    cout<<p[a[0]-'0']*p[a[1]-'0']<<endl;
 
    //system("pause");
    return 0;
}