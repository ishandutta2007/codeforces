#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin >> n;
int l;
l=( -1+sqrt(1+(8*n)) )/2;
string s;
cin >> s;
int temp=0;
for(int i=1;i<=l;i++)
{
    temp=temp+i;
cout << s[temp-1];
}




return 0;
}