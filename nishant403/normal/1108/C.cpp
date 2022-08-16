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

 string st;
 cin >> st;

int count=0;
//RGB index 0 , 1 , 2 with modulos in next dimension
int noteit[3][3]={0};
for(i=0;i<n;i++) 
{
    if(st[i]=='G') noteit[1][i%3]++;
    else if(st[i]=='R') noteit[0][i%3]++;
    else noteit[2][i%3]++;
    
}

int row,col;
int max=0;
int arrange[3]={0};

int counter=0;

if( noteit[0][0]+noteit[1][1]+noteit[2][2] > max)
{
    max=noteit[0][0]+noteit[1][1]+noteit[2][2];
    counter=1;
}
if( noteit[0][0]+noteit[1][2]+noteit[2][1] > max)
{
    max=noteit[0][0]+noteit[1][2]+noteit[2][1];
    counter=2;
}
if( noteit[1][0]+noteit[0][1]+noteit[2][2] > max)
{
    max=noteit[1][0]+noteit[0][1]+noteit[2][2];
    counter=3;
}

if( noteit[1][0]+noteit[0][2]+noteit[2][1] > max)
{
    max=noteit[1][0]+noteit[0][2]+noteit[2][1];
    counter=4;
}
if( noteit[2][0]+noteit[0][1]+noteit[1][2] > max)
{
    max=noteit[2][0]+noteit[0][1]+noteit[1][2];
    counter=5;
}
if( noteit[2][0]+noteit[1][1]+noteit[0][2] > max)
{
    max=noteit[2][0]+noteit[1][1]+noteit[0][2];
    counter=6;
}

cout << n-max << "\n";

string s;
if(counter==1) s="RGB";
else if(counter==2) s="RBG";
else if(counter==3) s="GRB";
else if(counter==4) s="GBR";
else if(counter==5) s="BRG";
else if(counter==6) s="BGR";

for(i=0;i<n/3;i++) cout << s;

for(i=0;i<n%3;i++) cout << s[i];





    return 0;
}