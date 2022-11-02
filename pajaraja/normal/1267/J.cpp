#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi = 3e6;
vector<int> ans;
int a[maxi];
int cnt[maxi];
int c[maxi];
void solve()
{
    int n;
    scanf("%d",&n);

    for (int i=1;i<=n;i++){
        c[i] = 0;
        cnt[i] = 0;
    }
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        c[x]++;
    }



    for (int i=1;i<=n;i++)
        if (c[i])
          cnt[c[i]]++;

   for (int i=1;i<=n;i++)
    cnt[i]+=cnt[i-1];

   int ans = n;

//   for (int i=1;i<=n;i++)
//    cout<<cnt[i]<<" ";
//   cout<<endl;

   for (int i=2;i<=n;i++){
    int rez = 0;
    int ima = 0;
    for (int j=1;j<=n/i+1;j++){
       int first = max((j-1)*i + 1, (i-1)*j);
       int sc = min(n, i*j);
       if (first>sc) continue;
       rez+=j*(cnt[sc] - cnt[first - 1]);
       ima+=cnt[sc] - cnt[first - 1];
    }
    if (ima == cnt[n])
     ans = min(ans, rez);
   }

   printf("%d\n",ans);
}

int main()
{
     int t;
    cin>>t;

    while(t--)
        solve();
}