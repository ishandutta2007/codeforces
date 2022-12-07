#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

typedef struct _bill{
    int h1;
    int h2;
    char bi;
}bill;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bill arr[3];

    for(int i=0;i<3;i++)
    {
        int a,b;
        cin>>a>>b;

        int max = a>b?a:b;
        int min = a>b?b:a;

        arr[i].h1 = max;
        arr[i].h2 = min;
        arr[i].bi = (char) ('A'+i);
    }
    
    if((arr[0].h1 == arr[1].h1) && (arr[0].h1 == arr[2].h1) && (arr[0].h1 == (arr[0].h2 + arr[1].h2 + arr[2].h2)))
    {
        int side = arr[0].h1;
        cout<<side<<endl;

        for(int i =0; i<arr[0].h2;i++)
        {
            for(int j=0;j<side;j++)
            {
                cout<<"A";
            }
            cout<<endl;
        }
        for(int i =0; i<arr[1].h2;i++)
        {
            for(int j=0;j<side;j++)
            {
                cout<<"B";
            }
            cout<<endl;
        }
        for(int i =0; i<arr[2].h2;i++)
        {
            for(int j=0;j<side;j++)
            {
                cout<<"C";
            }
            cout<<endl;
        }
        return 0;
    }

    int sep = 0;
    int un1 = 1;
    int un2 = 2;
    if(arr[un1].h1 == arr[un2].h1)
    {
        int sum = arr[un1].h2 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
        
    }

    if(arr[un1].h2 == arr[un2].h2)
    {
        int sum = arr[un1].h1 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
        
    }

    if(arr[un1].h1 == arr[un2].h2)
    {
        int sum = arr[un1].h2 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h2 == arr[un2].h1)
    {
        int sum = arr[un1].h1 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    sep = 1;
    un1 = 0;
    un2 = 2;
    if(arr[un1].h1 == arr[un2].h1)
    {
        int sum = arr[un1].h2 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h2 == arr[un2].h2)
    {
        int sum = arr[un1].h1 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h1 == arr[un2].h2)
    {
        int sum = arr[un1].h2 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h2 == arr[un2].h1)
    {
        int sum = arr[un1].h1 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }


    sep = 2;
    un1 = 1;
    un2 = 0;
    if(arr[un1].h1 == arr[un2].h1)
    {
        int sum = arr[un1].h2 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h2 == arr[un2].h2)
    {
        int sum = arr[un1].h1 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h1 == arr[un2].h2)
    {
        int sum = arr[un1].h2 + arr[un2].h1;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h1+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h1;i++)
            {
                for(int j=0;j<arr[un1].h2;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h1;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }

    if(arr[un1].h2 == arr[un2].h1)
    {
        int sum = arr[un1].h1 + arr[un2].h2;
        if((sum == arr[sep].h1)&& (sum==arr[un1].h2+arr[sep].h2))
        {
            cout<<sum<<endl;
            for(int i=0;i<arr[sep].h2;i++)
            {
                for(int j=0;j<sum;j++)
                {
                    cout<<arr[sep].bi;
                }
                cout<<endl;
            }
            for(int i=0;i<arr[un1].h2;i++)
            {
                for(int j=0;j<arr[un1].h1;j++)
                {
                    cout<<arr[un1].bi;
                }
                for(int j=0;j<arr[un2].h2;j++)
                {
                    cout<<arr[un2].bi;
                }
                cout<<endl;
            }
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}