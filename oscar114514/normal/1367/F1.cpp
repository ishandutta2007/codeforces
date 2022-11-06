#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[233333];
map<int,int> cnt,L,R;
map<int,vector<int> > pos;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt.clear();L.clear();R.clear();
		pos.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
			pos[a[i]].push_back(i);
			R[a[i]]=i;
			if(!L[a[i]])L[a[i]]=i;
		}
		int ans=1;
		int cur=0,last=0;
		cnt[-1]=0;cnt[1000000007]=0;
		for(auto it=cnt.begin();it!=cnt.end();++it)
		{
			if(it->second==0)continue;
			int num=it->first;
//			cerr<<"solve "<<num<<", cur="<<cur<<", last="<<last<<endl;
			if(L[num]>last)
			{
//				cerr<<"case 1"<<endl;
				cur+=it->second;
			}
			else //L[num]<last
			{
//				cerr<<"case 2"<<endl;
				auto zz=lower_bound(pos[num].begin(),pos[num].end(),last);
				cur+=pos[num].end()-zz;
//				cerr<<"upd "<<cur<<' '<<cnt[num]<<endl;
				ans=max(ans,cur);
//				ans=max(ans,cnt[num]);
				auto tmp=it;
				--tmp;
				int ls=tmp->first;
				auto tt=lower_bound(pos[ls].begin(),pos[ls].end(),L[num]);
				cur=tt-pos[ls].begin();
				cur+=it->second;
			}
			last=R[num];
		}
		ans=max(ans,cur);
		cout<<n-ans<<endl;
	}
	return 0;
}