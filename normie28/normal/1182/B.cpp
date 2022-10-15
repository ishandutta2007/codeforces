#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int64_t h,w,i,j,col,row,fcol,frow,plus,top,bot,len,rin,count; char mp[502][502];
	fcol=false;frow=false; plus=true;
	cin>>h>>w;
	for (i=1;i<=h;i++) for (j=1;j<=w;j++) cin>>mp[i][j];
    for (i=1;i<=h;i++) {count=0; for (j=1;j<=w;j++) if (mp[i][j]=='*') count++; if (count>=2) 
    {if ((frow)or(count==2)) plus=false; else {frow=true;row=i;}} 
    }
    for (j=1;j<=w;j++) {count=0; for (i=1;i<=h;i++) if (mp[i][j]=='*') count++; if (count>=2) 
    {if ((fcol)or(count==2)) plus=false; else {fcol=true;col=j;}} 
    }
    if (mp[row][col]!='*') plus=false; else {
    top=row;bot=row;rin=col;len=col;
    while ((mp[row][rin]=='*')and(rin<=w)) rin++; rin--;
    while ((mp[row][len]=='*')and(len>=1)) len--; len++;
    while ((mp[top][col]=='*')and(top>=1)) top--; top++;
    while ((mp[bot][col]=='*')and(bot<=h)) bot++; bot--;
    if ((rin==col)or(len==col)or(top==row)or(bot==row)) plus=false;
    if (rin!=w) for (i=w;i>rin;i--) for (j=1;j<=h;j++) if (mp[j][i]=='*') plus=false; 
    if (bot!=h) for (i=h;i>bot;i--) for (j=1;j<=w;j++) if (mp[i][j]=='*') plus=false;
    if (len!=1) for (i=1;i<len;i++) for (j=1;j<=h;j++) if (mp[j][i]=='*') plus=false;
    if (top!=1) for (i=1;i<top;i++) for (j=1;j<=w;j++) if (mp[i][j]=='*') plus=false;

    }
    if (plus) cout<<"YES"; else cout<<"NO";
}