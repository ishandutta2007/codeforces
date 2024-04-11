#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int n;
bool inside(int x,int y)
{
    if(x<n&&y<n)
        return true;
    return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int k;
    cin >> n >> k;
    //scanf("%i %i",&n,&k);
    vector<string> mat(n);
    for(int i=0;i<n;i++)
    {
        cin >> mat[i];
    }
    vector<vector<int> > visited(n,vector<int>(n));
    set<pair<pair<int,char>,pair<int,int> > > q;
    q.insert({{0,mat[0][0]},{0,0}});
    visited[0][0]=1;
    set<pair<char,pair<int,int> > > s,d;
    int x=-1,y=-1;
    while((*q.begin()).first.first!=k+1)
    {
        pair<int,int> tr=(*q.begin()).second;
        pair<pair<int,char>,pair<int,int> > lol=(*q.begin());
        if(lol.first.first==k)
        {
            d.insert({mat[lol.second.first][lol.second.second],{lol.second.first,lol.second.second}});
        }
        q.erase(q.begin());
        //printf("%i %c %i %i\n",lol.first.first,lol.first.second,lol.second.first,lol.second.second);
        int x=lol.second.first;
        int y=lol.second.second;
        if(tr==make_pair(n-1,n-1))
        {
            for(int i=0;i<2*n-2;i++)
            {
            	cout << "a";
               // printf("%c",'a');
            }
            if(k==lol.first.first)
            {
            	if(lol.first.second!='a')
            	{
            		cout << lol.first.second;
            	}
            	else
            	{
            		cout << 'a';
            	}
            }
            else
            {
            	cout << 'a';
            }
            //printf("\n");
            cout << "\n";
            return 0;
        }
        if(inside(x+1,y)&&visited[x+1][y]==0)
        {
            if(mat[x][y]=='a')
            {
                //printf("%i %i\n",x+1,y);
                q.insert({{lol.first.first,mat[x+1][y]},{x+1,y}});
            }
            else
            {
                q.insert({{lol.first.first+1,mat[x+1][y]},{x+1,y}});
            }
            visited[x+1][y]=1;
        }
        if(inside(x,y+1)&&visited[x][y+1]==0)
        {
            if(mat[x][y]=='a')
            {
                q.insert({{lol.first.first,mat[x][y+1]},{x,y+1}});
            }
            else
            {
                q.insert({{lol.first.first+1,mat[x][y+1]},{x,y+1}});
            }
            visited[x][y+1]=1;
        }
    }
    int maxx=0;
    for(auto p:d)
    {
    	//printf("%c  %i %i\n",p.first,p.second.first,p.second.second);
    	maxx=max(maxx,p.second.first+p.second.second);
    }
    for(auto p:d)
    {
    	if(p.second.first+p.second.second==maxx)
    	{
    		//printf("drugo %c  %i %i\n",p.first,p.second.first,p.second.second);
    	
    		s.insert(p);
    	}
    }
    string st;
    for(int i=0;i<maxx;i++)
    {
        st+='a';
    }

    for(int l=0;l<2*n-k;l++)
    {
        set<pair<int,int> > minn;
        st+=(*s.begin()).first;
        for(auto p:s)
        {
            //printf("%c %i %i\n",p.first,p.second.first,p.second.second);
            if(p.first==(*s.begin()).first)
            {
                minn.insert(p.second);
            }
        }
        s.clear();
        for(auto p:minn)
        {
            int i=p.first;
            int j=p.second;
            if(inside(i+1,j))
            s.insert({mat[i+1][j],{i+1,j}});
            if(inside(i,j+1))
            s.insert({mat[i][j+1],{i,j+1}});
        }
    }
    for(int i=0;i<2*n-1;i++)
    {
    	cout << st[i];
        //printf("%c",st[i]);
    }
    //printf("\n");
    cout << "\n";
    return 0;
    //cout << st << "\n";
    return 0;
}