#include <bits/stdc++.h>
using namespace std;
 
int n,p,flag=0,potato=0,tomato=0;
string z;
 
void f(int x)
{
    for(char i = p ; i>='a' ; i--)
    {
        if(z[x-1]!=i && z[x-2]!=i) {
            z[x] = i;
        }
    }
}
int main()
{
cin >> n >> p;
if(p==2 && n > 2)
{
    cout << "NO";
    return 0;
}
else if(p==1 && n>1)
{
    cout << "NO";
    return 0;
}
else
    p=p+96;
cin>> z;
 
    for(int i=n-1;i>=0;i--)
    {
        flag=0;
        for(int j = z[i] + 1; j<=p ; j++)
        {
            if(char(j)!=z[i-1] && char(j)!=z[i-2])
            {
                z[i] = j;
                flag++;
                break;
            }
        }
        for(int k = i + 1 ; k<n ; k++)
        {
            f(k);
 
        }
        if(flag)
        {
            cout << z;
            return 0;
        }
    }
    puts("NO");
}