#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
   int ax,ay,bx,by,cx,cy;
   cin>>ax>>ay>>bx>>by>>cx>>cy;
   if(ax==bx && ax==cx)
   {
       int a=min(ay,by);
       a=min(a,cy);
       int b=max(ay,by);
       b=max(b,cy);
       cout<<b-a+1<<endl;
       for(int j=a;j<=b;j++)
        {
            cout<<ax<<" "<<j<<endl;
        }
        return 0;
   }
   vector<pair<int,int> > ans;
   if(cx<ax)
   {
       swap(ax,cx); swap(ay,cy);
   }
   if(cx<bx)
   {
       swap(bx,cx); swap(by,cy);
   }
   if(ax>bx)
   {
       swap(ax,bx); swap(ay,by);
   }
   if(ax>cx)
   {
       swap(ax,cx); swap(ay,cy);
   }
   if(ay>=cy)
   {
       if(ay>=by)
       {
            for(int i=ay;i>=max(by,cy);i--)
            {
                ans.push_back({ax,i});
            }
            for(int i=ax+1;i<=cx;i++)
            {
                ans.push_back({i,max(by,cy)});
            }
            if(cy>by)
            {
                for(int i=cy-1;i>=by;i--)
                {
                    ans.push_back({bx,i});
                }
            }
            if(by>cy)
            {
                for(int i=by-1;i>=cy;i--)
                {
                    ans.push_back({cx,i});
                }
            }
       }
       if(by>ay)
       {
           for(int i=ax;i<=cx;i++)
           {
               ans.push_back({i,ay});
           }
           for(int i=ay-1;i>=cy;i--)
           {
               ans.push_back({cx,i});
           }
           for(int i=ay+1;i<=by;i++)
           {
               ans.push_back({bx,i});
           }
       }

   }
   if(cy>ay)
   {
       if(by>=ay)
       {
           for(int i=ay;i<=min(by,cy);i++)
           {
               ans.push_back({ax,i});
           }
           for(int i=ax+1;i<=cx;i++)
           {
               ans.push_back({i,min(by,cy)});
           }
           if(cy>=by)
           {
               for(int i=by+1;i<=cy;i++)
               {
                   ans.push_back({cx,i});
               }
           }
           if(cy<by)
           {
               for(int i=cy+1;i<=by;i++)
               {
                   ans.push_back({bx,i});
               }
           }
       }
       if(by<ay)
       {
           for(int i=ax;i<=cx;i++)
           {
               ans.push_back({i,ay});
           }
           for(int i=ay+1;i<=cy;i++)
           {
               ans.push_back({cx,i});
           }
           for(int i=ay-1;i>=by;i--)
           {
               ans.push_back({bx,i});
           }
       }
   }
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;

    return 0;
}