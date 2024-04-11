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
    int n,m;
    cin>>n>>m;
    point first[n];
    int numerouno[10]={0};
    int numero[10]={0};
    for(int i=0;i<n;i++)
    {
      int a;
      int b;
      cin>>a>>b;
      numerouno[a]++;
      numerouno[b]++;
      if(a<b)
      {
         first[i].x = a;
         first[i].y = b;
      }
      else
      {
         first[i].x = b;
         first[i].y = a;
      }
    }
    point second[m];
    for(int i=0;i<m;i++)
    {
      int a;
      int b;
      cin>>a>>b;
      numero[a]++;
      numero[b]++;
      if(a<b)
      {
         second[i].x = a;
         second[i].y = b;
      }
      else
      {
         second[i].x = b;
         second[i].y = a;
      }
    }
    int arr[10]= {0};
    sort(first, first+n, waytosort);
    sort(second, second+m, waytosort);

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
         if(first[i].x == second[j].x && first[i].y != second[j].y)
            arr[first[i].x]=1;
         if(first[i].x != second[j].x && first[i].y == second[j].y)
            arr[first[i].y]=1;
         if(first[i].x != second[j].y && first[i].y == second[j].x)
            arr[first[i].y]=1;
         if(first[i].x == second[j].y && first[i].y != second[j].x)
            arr[first[i].x]=1;
      }
    }

    int num = 0;
    int answer;
    for(int i=0;i<10;i++)
    {
      if(arr[i]==1)
      {
         num++;
         answer = i;
      }
    }
    if(num==1)
    {
      cout<<answer<<endl;
      return 0;
    }

    for(int i=0;i<n;i++)
    {
      if(arr[first[i].x]==1 && arr[first[i].y]==1)
      {
        int check =0;
        if(numero[first[i].x]>1)
            check++;
        else
        {
            for(int j=0;j<m;j++)
            {
                if(second[j].x==first[i].x)
                {
                    if(second[j].y!=first[i].y)
                        check++;
                    break;
                }
                else if(second[j].y==first[i].x)
                {
                    if(second[j].x!=first[i].y)
                        check++;
                    break;
                }
            }
        }
        
        if(numero[first[i].y]>1)
            check++;
        else
        {
            for(int j=0;j<m;j++)
            {
                if(second[j].x==first[i].y)
                {
                    if(second[j].y!=first[i].x)
                        check++;
                    break;
                }
                else if(second[j].y==first[i].y)
                {
                    if(second[j].x!=first[i].x)
                        check++;
                    break;
                }
            }
        }
        if(check==2)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        
      }
    }
    for(int i=0;i<m;i++)
    {
      if(arr[second[i].x]==1 && arr[second[i].y]==1)
      {
        int check =0;
        if(numerouno[second[i].x]>1)
            check++;
        else
        {
            for(int j=0;j<n;j++)
            {
                if(first[j].x==second[i].x)
                {
                    if(first[j].y!=second[i].y)
                        check++;
                    break;
                }
                else if(first[j].y==second[i].x)
                {
                    if(first[j].x!=second[i].y)
                        check++;
                    break;
                }
            }
        }
        
        if(numerouno[second[i].y]>1)
            check++;
        else
        {
            for(int j=0;j<n;j++)
            {
                if(first[j].x==second[i].y)
                {
                    if(first[j].y!=second[i].x)
                        check++;
                    break;
                }
                else if(first[j].y==second[i].y)
                {
                    if(first[j].x!=second[i].x)
                        check++;
                    break;
                }
            }
        }
        if(check==2)
        {
            cout<<"-1"<<endl;
            return 0;
        }
      }
    }

    cout<<"0"<<endl;
    return 0;
}