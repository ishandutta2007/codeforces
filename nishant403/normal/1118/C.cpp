    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    //   freopen("input.txt","r",stdin);

        int n,i,j,k=1,t,od;
        int c[1001]={0};
        cin >> n;
        int m[n][n];

        f(i,n*n) {
        cin >> t;  c[t]++;

        }

        f(i,1001) if(c[i]&1) od=i;

        f(i,n/2) f(j,n/2)
        {

        while( c[k]<4 && k<1001) k++;
        if(k==1001) { cout << "NO"; return 0;}
        c[k]-=4;

        m[i][j]=k;
        m[n-i-1][j]=k;
        m[i][n-1-j]=k;
        m[n-i-1][n-j-1]=k;
        }

        if(n&1)
        {
         k=1;
         f(i,n/2)
        {
        while(c[k]<2 && k<1001) k++;
        if(k==1001) { cout << "NO"; return 0;}
        c[k]-=2;

        m[i][n/2]=k;
        m[n-i-1][n/2]=k;
        }

         f(i,n/2)
        {
        while(c[k]<2 && k<1001) k++;
        if(k==1001) { cout << "NO"; return 0;}
        c[k]-=2;

        m[n/2][i]=k;
        m[n/2][n-i-1]=k;
        }

        m[n/2][n/2]=od;
        }

        cout <<"YES\n";
        f(i,n) { f(j,n) cout << m[i][j] << " "; cout << "\n"; }

        return 0;
    }