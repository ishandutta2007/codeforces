// yiikaoby
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int main(){
	int t=gi();
	while(t--){
		int n=gi();
		std::vector<std::vector<int> >A,B;
		A.push_back(std::vector<int>()),B.push_back(std::vector<int>());
		for(int i=1;i<=n/2;++i)A[0].push_back(i);
		for(int i=n/2+1;i<=n;++i)B[0].push_back(i);
		int ans=0;
		while(A.size()&&B.size()){
			int a=0,b=0;
			for(auto i:A)for(auto j:i)++a;
			for(auto i:B)for(auto j:i)++b;
			printf("%d %d ",a,b);
			for(auto i:A)for(auto j:i)printf("%d ",j);
			for(auto i:B)for(auto j:i)printf("%d ",j);
			puts("");
			fflush(stdout);
			ans=std::max(gi(),ans);
			std::vector<std::vector<int> >AA,BB;
			for(auto i:A){
				if(i.size()<2)continue;
				bool x=0;
				AA.push_back(std::vector<int>()),BB.push_back(std::vector<int>());
				for(auto j:i)
					if(x)x=0,AA.back().push_back(j);
					else x=1,BB.back().push_back(j);
			}
			for(auto i:B){
				if(i.size()<2)continue;
				bool x=0;
				AA.push_back(std::vector<int>()),BB.push_back(std::vector<int>());
				for(auto j:i)
					if(x)x=0,AA.back().push_back(j);
					else x=1,BB.back().push_back(j);
			}
			A=AA,B=BB;
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
}