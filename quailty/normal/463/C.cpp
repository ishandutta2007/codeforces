#include <bits/stdc++.h>
#define ll long long
#define p(x) cout<<#x<<x<<endl;
#define MAX 2010
using namespace std;
ll int sumr[MAX][MAX],suml[MAX][MAX],a[MAX][MAX];
int main()
{
    ll int n,i,j,x1=1,x2=1,y1=1,y2=2;
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {scanf("%I64d",&a[i][j]);
                //cout<<a[i][j];
                }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            sumr[i][j]=sumr[i-1][j-1]+a[i][j];
            //p(sumr[i][j]);
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=n;j>=1;j--)
        {
            suml[i][j]=suml[i-1][j+1]+a[i][j];
        }
    }
    ll int val1=0,val2=0,right=0,left=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j>=i)
            {
//                p(i);
//                p(j);
//                p(n-(j-i));
                right=sumr[n-(j-i)][n];
            }
            else
            {
//                p(i);
//                p(j);
//                p(n-(i-j));
                right=sumr[n][n-(i-j)];
            }

            if((n-j+1)>=i)
            {
//                p(i);
//                p(j);
                //p(n-i);
//                p(n-((n-j+1)-i));
                left=suml[n-((n-j+1)-i)][1];
            }
            else
            {
//                p(i);
//                p(j);
//                // p(n-i);
//                p(n-(n-(i-(n-j+1)))+1);
               left=suml[n][n-(n-(i-(n-j+1)))+1];
            }
//            p(right);
//            p(left);
            if((i+j)%2==0)
            {
                if(right+left-a[i][j]>val1)
                {
                    x1=i;
                    y1=j;
                    val1=right+left-a[i][j];
                }
            }
            else
            {
                if(right+left-a[i][j]>val2)
                {
                    x2=i;
                    y2=j;
                    val2=right+left-a[i][j];
                }
            }
        }
    }
    cout<<val1+val2<<endl;
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}