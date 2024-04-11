#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=2000+5;
struct Tri{
	int f,l,r;
	Tri(){
		f=l=r=-1e9;
	}
	Tri(int _f,int _l,int _r):f(_f),l(_l),r(_r){
	}
	Tri operator ()(int _l,int _r){
		return Tri(f,l*_l,r*_r);
	}
};
Tri operator +(const Tri &a,const Tri &b){
	return Tri(a.f+b.f,a.l,b.r);
}
bool operator ==(const Tri &a,const Tri &b){
	return a.f==b.f&&a.l==b.l&&a.r==b.r;
}
Tri operator +(const Tri &a,int x){
	return Tri(a.f+x,a.l,a.r);
}
void chmax(Tri &a,const Tri &b){
	if(a.f<b.f)a=b;
}
vector<Tri> dp[N][2][2],pre[N][2][2];
vector<int> lk[N];
void clear(vector<Tri> &a,int l,int r){
	while(!a.empty()&&a.back().f<0)a.pop_back();
/*	for(auto &t:a){
		t.l*=l;
		t.r*=r; 
	}*/
}

pair<int,int> ans[N],seg[N];
int n;
void print_dp(int x,int tl,int tr,int tj,vector<int> &q){
	if(lk[x].empty()){
		ans[x]=seg[x];
		return ;
	}
	
	Tri tf=dp[x][tl][tr][tj];
	if(tl&&dp[x][0][tr][tj](0,tr)==tf)--tl;
	if(tr&&dp[x][tl][0][tj](tl,0)==tf)--tr;
	if(dp[x][0][0][tj](0,0)==tf)tl=tr=0;
	tf=dp[x][tl][tr][tj];
	//tf=tf(tl,tr);
	//cerr<<x<<" "<<tl<<" "<<tr<<" "<<tj<<" "<<tf.f<<endl; 
	
	int ny=lk[x].back();
			int L=seg[lk[x][0]].first-seg[x].first,R=seg[x].second-seg[ny].second;
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r)
			for(int j=0;j<int(pre[ny][l][r].size());++j){
				Tri f=pre[ny][l][r][j](l,r);
				if(l){
					f.f+=L;
					f.l+=L;
				}
				if(r){
					f.f+=R;
					f.r+=R;
				}
				if(l==tl&&r==tr&&j-1==tj&&f==tf){
					tj=j;
					q.push_back(x);
					
					goto End;
				}
				if(j<=n){
					if(l && 0==tl && r==tr && j==tj && f==tf){
						tl=l;
						ans[x]={seg[x].first,seg[x].first+f.l};
						goto End;
					}
					if(r && l==tl && 0==tr && j==tj && f==tf){
						tr=r;
						ans[x]={seg[x].second-f.r,seg[x].second};
						goto End;
					}
				}
				if(j+1<=n&&l&&r && tl==0&& tr==0&&j+1==tj && f==tf){
					tl=l;tr=r;tj=j;
					ans[x]={seg[x].first,seg[x].first+f.l};
					ans[q.back()]={seg[x].second-f.r,seg[x].second};
					q.pop_back();
					
					goto End;
				}
			}
			
	//cerr<<x<<" "<<tl<<" "<<tr<<" "<<tj<<endl; 
	End:;
	for(int head=lk[x].size()-1;head;--head){
		int y=lk[x][head];
		int ny=-1;
		if(head)ny=lk[x][head-1];
		tf=pre[y][tl][tr][tj];
		int mid=seg[y].first-seg[ny].second;
					for(int l1=0;l1<2;++l1)
					for(int r1=0;r1<2;++r1)
					for(int j1=0;j1<int(pre[ny][l1][r1].size());++j1)
					for(int l2=0;l2<2;++l2)
					for(int r2=0;r2<2;++r2)
					for(int j2=0;j2<int(dp[y][l2][r2].size());++j2){
						if(j1+j2+1<=n){
							if(l1==tl&&r2==tr&&j1+j2+1==tj&&(pre[ny][l1][r1][j1](l1,r1)+dp[y][l2][r2][j2](l2,r2)+mid)==tf){
								ans[q.back()]={seg[ny].second-pre[ny][l1][r1][j1](l1,r1).r,
												seg[y].first+dp[y][l2][r2][j2](l2,r2).l};
								q.pop_back();
								print_dp(y,l2,r2,j2,q);
								tr=r1;tj=j1;
								goto End2;
							}
						}
						if(j1+j2<=n&&l2==0&&r1==0){
							if(l1==tl&&r2==tr&&j1+j2==tj&&(pre[ny][l1][r1][j1](l1,r1)+dp[y][l2][r2][j2](l2,r2))==tf){
								print_dp(y,l2,r2,j2,q);
								tr=r1;tj=j1;
								goto End2;
							}
						}
					}
			End2:;
	}
	print_dp(lk[x][0],tl,tr,tj,q);
}

int main(){
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n;
	for(int i=0;i<n;++i)scanf("%d%d",&seg[i].first,&seg[i].second);
	vector<int> q(n);
	for(int i=0;i<n;++i)q[i]=i;
	sort(q.begin(),q.end(),[&](int x,int y){return seg[x].first>seg[y].first;});
	vector<int>fa(n,-1);
	for(auto x:q){
		int now=seg[x].first;
		while(1){
			int ny=-1;
			for(int y=0;y<n;++y)
			if(seg[y].first>now&&(ny==-1||seg[y].first<seg[ny].first))
				ny=y;
			if(ny!=-1&&seg[ny].second<seg[x].second){
				fa[ny]=x;
				lk[x].push_back(ny);
				now=seg[ny].second;
			}
			else break;
		}
		if(lk[x].empty()){
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r){
				dp[x][l][r].push_back(Tri(seg[x].second-seg[x].first,0,0));
			}
		}else{
			int ny=-1;
			for(auto y:lk[x]){
				if(ny==-1){
					for(int l=0;l<2;++l)
					for(int r=0;r<2;++r)pre[y][l][r]=dp[y][l][r];
				}else{
					for(int l=0;l<2;++l)
					for(int r=0;r<2;++r)pre[y][l][r].resize(n+1);
					int mid=seg[y].first-seg[ny].second;
					for(int l1=0;l1<2;++l1)
					for(int r1=0;r1<2;++r1)
					for(int j1=0;j1<int(pre[ny][l1][r1].size());++j1)
					for(int l2=0;l2<2;++l2)
					for(int r2=0;r2<2;++r2)
					for(int j2=0;j2<int(dp[y][l2][r2].size());++j2){
						if(j1+j2+1<=n){
							chmax(pre[y][l1][r2][j1+j2+1],pre[ny][l1][r1][j1](l1,r1)+dp[y][l2][r2][j2](l2,r2)+mid);
						}
						if(j1+j2<=n&&l2==0&&r1==0){
							chmax(pre[y][l1][r2][j1+j2],pre[ny][l1][r1][j1](l1,r1)+dp[y][l2][r2][j2](l2,r2));
						}
					}
					for(int l=0;l<2;++l)
					for(int r=0;r<2;++r)clear(pre[y][l][r],l,r);
				}
				ny=y;
			}
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r)dp[x][l][r].resize(n+1);
			int L=seg[lk[x][0]].first-seg[x].first,R=seg[x].second-seg[ny].second;
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r)
			for(int j=0;j<int(pre[ny][l][r].size());++j){
				Tri f=pre[ny][l][r][j](l,r);
				if(l){
					f.f+=L;
					f.l+=L;
				}
				if(r){
					f.f+=R;
					f.r+=R;
				}
				if(j)chmax(dp[x][l][r][j-1],f);
				if(j<=n){
					if(l)
						chmax(dp[x][0][r][j],f);
					if(r)
						chmax(dp[x][l][0][j],f);
				}
				if(j+1<=n&&l&&r)
					chmax(dp[x][0][0][j+1],f);
			}
				
			//cerr<<x<<" ";
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r)
			for(int l1=0;l1<=l;++l1)
			for(int r1=0;r1<=r;++r1)
			for(int j=0;j<=n;++j)chmax(dp[x][l][r][j],dp[x][l1][r1][j](l1,r1));
			
			for(int l=0;l<2;++l)
			for(int r=0;r<2;++r){
				clear(dp[x][l][r],l,r);
				//cerr<<dp[x][l][r].size()<<" ";
			}
			//cerr<<endl;
		}
	}
	vector<int> rt;
	int sum=0;
	for(int x=0;x<n;++x)
	if(fa[x]==-1){
		rt.push_back(x);
		sum+=dp[x][0][0][0].f;
		vector<int>qu;
		print_dp(x,0,0,0,qu);
	}
	cout<<sum<<endl;
	for(int i=0;i<n;++i)printf("%d %d\n",ans[i].first,ans[i].second);
	for(int i=0;i<n;++i)sum-=ans[i].second-ans[i].first;
//	cout<<sum<<endl;
}