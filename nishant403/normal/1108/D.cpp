#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    int n;
    cin >> n;

 string s;
 cin >> s;

int count=0;
int temp=1;
for(i=1;i<n;i++)
{
    if(s[i]==s[i-1])
    temp++;

    else
    {
        count+=temp/2;
        temp=1;
    }

}

count+=temp/2;
cout << count << "\n";

for(i=1;i<n-1;i++)
{
    if(s[i]==s[i-1])
    {
        if(s[i-1]=='R' && s[i+1]=='G')  s[i]='B';
       else if(s[i-1]=='R' && s[i+1]=='B')  s[i]='G';
      else  if(s[i-1]=='R' && s[i+1]=='R')  s[i]='G';
        else if(s[i-1]=='B' && s[i+1]=='G')  s[i]='R';
       else if(s[i-1]=='B' && s[i+1]=='R')  s[i]='G';
        else if(s[i-1]=='B' && s[i+1]=='B')  s[i]='R';
       else if(s[i-1]=='G' && s[i+1]=='G')  s[i]='B';
       else if(s[i-1]=='G' && s[i+1]=='B')  s[i]='R';
       else if(s[i-1]=='G' && s[i+1]=='R')  s[i]='B';
}

}
if(s[n-2]==s[n-1])
{
    if(s[n-2]=='R') s[n-1]='G';

    else if(s[n-2]=='G') s[n-1]='R';

    else if(s[n-2]=='B') s[n-1]='G';


}
cout << s;

    return 0;
}