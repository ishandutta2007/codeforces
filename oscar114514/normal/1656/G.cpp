#include<bits/stdc++.h>
using namespace std;
int a[233333];
vector<int> vec[233333],pos[233333];
int ans[233333],vis[233333],pa[233333];
int find(int x){return pa[x]?pa[x]=find(pa[x]):x;}
int main()
{
	int T,n;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>n;
		int idx=0;
		for(int i=1;i<=n;i++)vec[i].clear(),pos[i].clear(),vis[i]=0,pa[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			vec[a[i]].push_back(i);
		}
		/*
		if(tt==294)
		{
			cout<<n<<endl;
			for(int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<endl;
			return 0;
		}
		if(T==30000)continue;
		*/
		int cnt=0;//,key=0;
		int mid=n/2+1;
		for(int i=1;i<=n;i++)
		{
			if(vec[i].size()%2==1)
			{
				cnt++;
				if(vec[i][0]==mid and (int)vec[i].size()>1)
				{
					a[vec[i][vec[i].size()-1]]=++idx;
					for(int j=0;j<(int)vec[i].size()-1;j+=2)
					{
						++idx;
						a[vec[i][j]]=a[vec[i][j+1]]=idx;
					}
				}
				else if(vec[i][0]!=mid)
				{
					a[vec[i][0]]=++idx;
					for(int j=1;j<(int)vec[i].size();j+=2)
					{
						++idx;
						a[vec[i][j]]=a[vec[i][j+1]]=idx;
					}
				}
				else
				{
					cnt=1e9;
					break;
				}
			}
			else
			{
				for(int j=0;j<(int)vec[i].size();j+=2)
				{
					++idx;
					a[vec[i][j]]=a[vec[i][j+1]]=idx;
				}
			}
		}
		if(cnt>1)
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
//			cerr<<a[i]<<' ';
			pos[a[i]].push_back(i);
		}
//		cerr<<endl;
		int l=1,r=n;
		for(int i=1;i<=idx;i++)
		{
			if((int)pos[i].size()==1)
			{
				ans[mid]=pos[i][0];
				pos[i][0]=mid;
				continue;
			}
			ans[l]=pos[i][0];ans[r]=pos[i][1];
			pos[i][0]=l;pos[i][1]=r;
			l++;r--;
		}
//		for(int i=1;i<=n;i++)cerr<<ans[i]<<' ';cerr<<endl;
		for(int i=1;i<=n;i++)
		{
			if(not vis[i])
			{
				for(int j=i;not vis[j];j=ans[j])
				{
					vis[j]=1;
					if(j!=i)pa[j]=i;
				}
			}
		}
		for(int i=1;i<=idx;i++)
		{
			if(pos[i].size()==1)continue;
			int pu=find(pos[i][0]),pv=find(pos[i][1]);
			if(pu!=pv)
			{
				swap(ans[pos[i][0]],ans[pos[i][1]]);
				swap(pos[i][0],pos[i][1]);
				pa[pv]=pu;
			}
		}
//		for(int i=1;i<=n;i++)cerr<<ans[i]<<' ';cerr<<endl;
		for(int i=1;i<=n;i++)vis[i]=0;
		int w=a[1];
		if(pos[w].size()==1)w=a[ans[1]];
		for(int i=1;i<=n;i++)
		{
			if(not vis[i])
			{
				for(int j=i;not vis[j];j=ans[j])
				{
					vis[j]=1;
				}
//				cerr<<"dfs "<<i<<endl;
				if(i==1)continue;
				int ww=a[i];
				if((int)pos[ww].size()==1)ww=a[ans[i]];
//				cerr<<pos[w][0]<<' '<<pos[w][1]<<' '<<pos[ww][0]<<' '<<pos[ww][1]<<endl;
				swap(ans[pos[ww][0]],ans[pos[ww][1]]);
				swap(pos[ww][0],pos[ww][1]);
				swap(ans[pos[ww][0]],ans[pos[w][0]]);
				swap(pos[ww][0],pos[w][0]);
				swap(ans[pos[ww][1]],ans[pos[w][1]]);
				swap(pos[ww][1],pos[w][1]);
			}
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<"\n";
	}
	
	return 0;
}