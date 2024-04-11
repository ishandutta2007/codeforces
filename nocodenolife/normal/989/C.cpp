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

struct Point
{
   int val;
   char letter;
};
typedef struct Point point;

bool waytosort(point x, point y)
{
   return (x.val<y.val);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    point arr[4] = {{a,'A'},{b,'B'},{c,'C'},{d,'D'}};

    sort(arr,arr+4,waytosort);
    int n= 24 + 2*((arr[0].val+24)/25);
    cout<<n<<" 50"<<endl;
    while(arr[0].val>25)
    {
      for(int i=0;i<50;i=i+2)
      {
         cout<<arr[0].letter<<arr[1].letter;
      }
      cout<<endl;
      for(int i=0;i<50;i=i+2)
      {
         cout<<arr[1].letter<<arr[1].letter;
      }
      cout<<endl;
      arr[0].val -=25;
    }

    int number = arr[0].val - 1;

    for(int j=0;j<number;j++)
    {
         cout<<arr[0].letter<<arr[1].letter;

    }
    for(int i=number*2;i<50;i++)
    {
      cout<<arr[1].letter;
   }
    arr[0].val = 1;
    arr[1].val-=1;
    cout<<endl;
    for(int i=0;i<50;i++)
    {
      cout<<arr[1].letter;
   }
   cout<<endl;



   for(int i=3;i>=1;i--)
   {
      int value = arr[i].val;
      char let = arr[i].letter;
      char al = arr[0].letter;
      if(value==0)
      {
         for(int k= 0;k<8;k++)
         {
            for(int j=0;j<50;j=j+2)
            {
               cout<<al<<al;
            }
            cout<<endl;
         }
         continue;
      }
      int rows = (value+24)/25;
      value -= (rows-1)*25;
      int printed =0;
      while(rows>1)
      {
         for(int j=0;j<50;j=j+2)
         {
            cout<<al<<let;
         }
         cout<<endl;
         for(int j=0;j<50;j=j+2)
         {
            cout<<al<<al;
         }
         cout<<endl;
         rows--;
         printed+=2;
      }
      for(int j=0;j<value;j++)
      {
         cout<<al<<let;
      }
      for(int j=value*2;j<50;j++)
      {
         cout<<al;
      }
      printed+=1;
      cout<<endl;
      for(int k= printed;k<8;k++)
      {
         for(int j=0;j<50;j=j+2)
         {
            cout<<al<<al;
         }
         cout<<endl;
      }

   }

    return 0;
}