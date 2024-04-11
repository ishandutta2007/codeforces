#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 200000
typedef long long LL;

int n,m,k,mk=0;
LL ans;
struct state{
	int to,val;
	bool operator < (const state &that)const{
		return this->val < that.val;
	}
};
std::vector<state> e[MN+5];
std::vector<int> s[10][10];
std::vector<int> chosen;

bool cross[100][100];

void search(int sz){
	if(sz>mk){
		ans++;
		return;
	}
	for(int i=1;i<=sz;i++){
		if(cross[sz*10+i][sz*10+i]) continue;
		bool flag = true;
		for(int j=0;j<chosen.size();j++){
			if(cross[sz*10+i][chosen[j]]){
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		chosen.push_back(sz*10+i);
		search(sz+1);
		chosen.pop_back();
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back((state){v,w});
	}
	for(int i=1;i<=n;i++){
		std::sort(e[i].begin(),e[i].end());
		int sz = e[i].size();
		mk = std::max(mk,sz);
		std::vector<int> *s = ::s[sz];
		for(int j=0;j<sz;j++){
			s[j+1].push_back(e[i][j].to);
		}
	}
	for(int s1_sz=1;s1_sz<=mk;s1_sz++){
		for(int s1_enum=1;s1_enum<=s1_sz;s1_enum++){
			std::sort(s[s1_sz][s1_enum].begin(),s[s1_sz][s1_enum].end());
			const std::vector<int> s = ::s[s1_sz][s1_enum];
			for(int i=1;i<s.size();i++)
				if(s[i-1]==s[i]) cross[s1_sz*10+s1_enum][s1_sz*10+s1_enum] = true;
		}
	}
	for(int s1_sz=1;s1_sz<=mk;s1_sz++){
		for(int s1_enum=1;s1_enum<=s1_sz;s1_enum++){
			const std::vector<int>& s1 = s[s1_sz][s1_enum];
			for(int s2_sz=s1_sz+1;s2_sz<=mk;s2_sz++){
				for(int s2_enum=1;s2_enum<=s2_sz;s2_enum++){
					const std::vector<int>& s2 = s[s2_sz][s2_enum];
					int s1_it=0,s2_it=0;
					cross[s1_sz*10+s1_enum][s2_sz*10+s2_enum] = false;
					for(;s1_it<s1.size();s1_it++){
						while(s2_it<s2.size()&&s2[s2_it]<s1[s1_it]) s2_it++;
						if(s2_it==s2.size()) break;
						if(s1[s1_it]==s2[s2_it]){
							cross[s1_sz*10+s1_enum][s2_sz*10+s2_enum] = true;
							break;
						}
					}
					cross[s2_sz*10+s2_enum][s1_sz*10+s1_enum] = cross[s1_sz*10+s1_enum][s2_sz*10+s2_enum];
				}
			}
		}
	}
	search(1);
	for(int i=mk+1;i<=k;i++)
		ans *= i;
	printf("%lld\n",ans);
}