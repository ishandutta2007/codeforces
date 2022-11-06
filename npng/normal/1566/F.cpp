#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
std::vector<std::pair<ll,ll> > excl(std::vector<std::pair<ll,ll> > LR){
	std::sort(LR.begin(),LR.end());
	std::vector<std::pair<ll,ll> > ret;
	for(auto [l, r]: LR){
		while(!ret.empty()){
			auto [a, b]=ret.back();
			if(a<=l&&r<=b){
				ret.pop_back();
			}
			else{
				break;
			}
		}
		if(ret.empty()||ret.back().first!=l){
			ret.emplace_back(l, r);
		}
    }
	return ret;
}
ll solve(std::vector<ll> A,std::vector<std::pair<ll,ll> > LR){
	LR=excl(LR);
	std::sort(A.begin(),A.end());
	A.insert(A.begin(),-(ll)1e11);
	A.push_back((ll)1e11);
	int N=A.size();
	vector<ll> DPL(N,(ll)1e15),DPR(N,(ll)1e15);
	int tp=0;
	DPL[0]=DPR[0]=0;
	for(int i=0; i<N-1; ++i){
        vector<pair<long long, long long> > targs;
        while(tp < (int)LR.size() && LR[tp].second < A[i+1]) targs.push_back(LR[tp++]);
        while(tp < (int)LR.size() && LR[tp].first <= A[i+1]) ++tp;
        for(int j=0; j<=(int)targs.size(); ++j)
        {
            long long lv = j == 0 ? 0LL : (targs[j-1].first - A[i]);
            long long rv = j == (int)targs.size() ? 0 : (A[i+1] - targs[j].second);

            long long lft = min(DPL[i] + lv, DPR[i] + 2*lv);
            DPR[i+1] = min(DPR[i+1], lft + rv);
            DPL[i+1] = min(DPL[i+1], lft + 2*rv);
        }
    }
    return max(DPR.back(), DPL.back());
}

int main()
{
    int T; cin >> T; while(T--)
    {
        int N, M; cin >> N >> M;
        vector<long long> V(N); for(auto&i: V) cin >> i;
        vector<pair<long long, long long> > U(M);
        for(auto&[a, b]: U) cin >> a >> b;
        cout << solve(V, U) << endl;
    }
    return 0;
}