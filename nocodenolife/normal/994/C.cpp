#include <bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

struct Point{
   int x;
   int y;
};
typedef struct Point point;

bool waytosort(point a, point b)
{
   if(a.x == b.x)
   {
      return a.y<b.y;
   }
   return a.x<b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    point par[4];
    for(int i=0;i<4;i++)
    {
      cin>>par[i].x;
      cin>>par[i].y;
    }
    point per[4];
    for(int i=0;i<4;i++)
    {
      cin>>per[i].x;
      cin>>per[i].y;
    }
    sort(par,par+4,waytosort);
    sort(per,per+4,waytosort);

    int xmax = par[3].x;
    int xmin = par[0].x;
    int ymax = par[3].y;
    int ymin = par[0].y;
    for(int i=0;i<4;i++)
    {
      int x1 = per[i].x;
      int y1 = per[i].y;
      if(x1 <= xmax && x1 >= xmin)
      {
         if(y1 <= ymax && y1 >= ymin)
         {
            cout<<"YES";
            return 0;
         }
      }
    }
    int x1 = per[1].x;
    int y1 = per[0].y;
    if(x1 <= xmax && x1 >= xmin)
    {
      if(y1 <= ymax && y1 >= ymin)
      {
          cout<<"YES";
          return 0;
      }
    }
    int summin = per[0].x+per[0].y;
    int summax = per[3].x+per[3].y;
    int diffmin = per[1].y-per[1].x;
    int diffmax = per[2].y-per[2].x;
    for(int i=0;i<4;i++)
    {
      int sum = par[i].x + par[i].y;
      int dif = par[i].y - par[i].x;
      if(sum>=summin && sum<=summax)
      {
         if(dif<=diffmax && dif>=diffmin)
         {
            cout<<"YES";
            return 0;
         }
      }
    }
    int sum = par[1].x + par[1].y;
    int dif = par[0].y - par[0].x;
    if(sum>=summin && sum<=summax)
    {
      if(dif<=diffmax && dif>=diffmin)
      {
          cout<<"YES";
          return 0;
      }
    }

    cout<<"NO";
    return 0;
}