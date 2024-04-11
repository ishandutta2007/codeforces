#include <bits/stdc++.h>
#define long long long

using namespace std;

const int maxn = 1000005;

int n;
int lmin[maxn];
int rmin[maxn];
int lmax[maxn];
int rmax[maxn];
long answer;

void solveBit(vector<int> ids) {
    vector<int> stMax;
    vector<long> sumL, sumR, sumIndex, sumIndexL, sumIndexR, sumLR;

    stMax.reserve(ids.size());
    sumL.reserve(ids.size());
    sumR.reserve(ids.size());
    sumIndex.reserve(ids.size());
    sumIndexL.reserve(ids.size());
    sumIndexR.reserve(ids.size());
    sumLR.reserve(ids.size());

    auto push = [&](int i) -> void {
        if (stMax.empty()) {
            stMax.push_back(i);
            sumL.push_back(lmax[i] - 1);
            sumR.push_back(rmax[i] + 1);
            sumIndex.push_back(i);
            sumIndexL.push_back(1ll * i * (lmax[i] - 1));
            sumIndexR.push_back(1ll * i * (rmax[i] + 1));
            sumLR.push_back(1ll * (rmax[i] + 1) * (lmax[i] - 1));
        } else {
            stMax.push_back(i);
            sumL.push_back(sumL.back() + lmax[i] - 1);
            sumR.push_back(sumR.back() + rmax[i] + 1);
            sumIndex.push_back(sumIndex.back() + i);
            sumIndexL.push_back(sumIndexL.back() + 1ll * i * (lmax[i] - 1));
            sumIndexR.push_back(sumIndexR.back() + 1ll * i * (rmax[i] + 1));
            sumLR.push_back(sumLR.back() + 1ll * (rmax[i] + 1) * (lmax[i] - 1));
        }
    };

    auto pop = [&]() -> void {
        stMax.pop_back();
        sumL.pop_back();
        sumR.pop_back();
        sumIndex.pop_back();
        sumIndexL.pop_back();
        sumIndexR.pop_back();
        sumLR.pop_back();
    };

    #define countRange(l, r) ((r) - (l) + 1ll)

    auto getRange = [&](vector<long> &prefixSum, int l, int r) -> long {
        if (r < l) return 0;
        if (l == 0) return prefixSum[r];
        return prefixSum[r] - prefixSum[l - 1];
    };

    for(int i: ids) {
        while(!stMax.empty() && rmax[stMax.back()] < i) pop();
        push(i);

        int start = lower_bound(stMax.begin(), stMax.end(), lmin[i]) - stMax.begin();
        // L in stack max increasing
        // R in stack max decreasing


        int breakL, breakR;
        /* Solve for L */ {
            int low = start, high = (int) stMax.size() - 1; 
            breakL = low - 1;
            while(low <= high) {
                int mid = (low + high) >> 1, index = stMax[mid];
                if (lmax[index] <= lmin[i]) {
                    low = mid + 1;
                    breakL = mid;
                } else {
                    high = mid - 1;
                }
            } 
        }


        /* Solve for R */ {
            int low = start, high = (int) stMax.size() - 1; 
            breakR = low - 1;
            while(low <= high) {
                int mid = (low + high) >> 1, index = stMax[mid];
                if (rmax[index] >= rmin[i]) {
                    low = mid + 1;
                    breakR = mid;
                } else {
                    high = mid - 1;
                }
            }
        }

        /* first case Li < Lj, Ri > Rj */ {
            int from = start, to = min(breakL, breakR);
            if (from <= to) {
                answer += getRange(sumIndex, from, to) * (rmin[i] + 1 - i);
                answer -= countRange(from, to) * 1ll * (lmin[i] - 1) * 1ll * (rmin[i] + 1);     
                answer += countRange(from, to) * (i * (lmin[i] - 1ll));
            }
        } 

        /* second case Li < Lj, Ri < Rj */ {
            int from = breakR + 1, to = breakL;
            if (from <= to) {

                answer += getRange(sumIndexR, from, to);
                answer -= getRange(sumIndex, from, to) * i;
                answer -= getRange(sumR, from, to) * (lmin[i] - 1);
                answer += 1ll * i * (lmin[i] - 1ll) * countRange(from, to);
            }
        }

        /* third case Li > Lj, Ri > Rj */ {
            int from = breakL + 1, to = breakR;
            if (from <= to) {
                answer += getRange(sumIndex, from, to) * (rmin[i] + 1 - i);
                answer -= getRange(sumL, from, to) * (rmin[i] + 1 - i);
            }
        }

        /* fourth case Li > Lj, Ri < Rj */ {
            int from = max(breakL, breakR) + 1, to = stMax.size() - 1;
            if (from <= to) {
                answer += getRange(sumIndexR, from, to);
                answer -= getRange(sumLR, from, to);
                answer -= getRange(sumIndex, from, to) * i;
                answer += getRange(sumL, from, to) * i;
            }
        }

    }
}

void solve(vector<long> a, bool reverted) {
    if (!reverted) {
        vector<int> stmin, stmax;
        for(int i = 0; i < n; ++i) {
            while(!stmin.empty() && a[i] <= a[stmin.back()]) {
                rmin[stmin.back()] = i - 1;
                stmin.pop_back();
            }
            while(!stmax.empty() && a[i] >= a[stmax.back()]) {
                rmax[stmax.back()] = i - 1;
                stmax.pop_back();
            }
            lmin[i] = lmax[i] = 0;
            if (!stmin.empty()) lmin[i] = stmin.back() + 1;
            if (!stmax.empty()) lmax[i] = stmax.back() + 1;
            stmin.push_back(i);
            stmax.push_back(i);
        }

        while(!stmin.empty()) {
            rmin[stmin.back()] = n - 1;
            stmin.pop_back();
        }

        while(!stmax.empty()) {
            rmax[stmax.back()] = n - 1;
            stmax.pop_back();
        }
    } else {
        reverse(a.begin(), a.end());
        reverse(lmin, lmin+n);
        reverse(lmax, lmax+n);
        reverse(rmin, rmin+n);
        reverse(rmax, rmax+n);

        for(int i = 0; i < n; ++i) {
            lmax[i] = n - lmax[i] - 1;
            lmin[i] = n - lmin[i] - 1;
            rmax[i] = n - rmax[i] - 1;
            rmin[i] = n - rmin[i] - 1;
            swap(lmin[i], rmin[i]);
            swap(lmax[i], rmax[i]);
        }
    }

    vector<vector<int>> hasBitCount(60);
    for(int i = 0; i < n; ++i) {
        hasBitCount[__builtin_popcountll(a[i])].push_back(i);
    } 

    for(int i = 0; i < 60; ++i) {
        solveBit(hasBitCount[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    vector<long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    solve(a, false);
    solve(a, true);

    int countEq = 0;
    for(int i = 0; i < n; ++i) {
        if (i > 0 && a[i] != a[i - 1]) countEq = 0;
        countEq++;
        answer -= countEq;
    }

    cout << answer << endl;

    return 0;
}