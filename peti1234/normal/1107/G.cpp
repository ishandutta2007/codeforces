#include <bits/stdc++.h>

using namespace std;
const int c=300002, k=20;
long long n, g, dif[c], cost[c], value[c], kom_value[c];
long long ans, gap[c], prev_big[c], next_big[c], logarithm[c], max_sparse[c][k], min_sparse[c][k];
vector<int> mins;
long long find_min(int l, int r) {
    long long lo=logarithm[r-l+1];
    //cout << "log " << lo << endl;
    //cout << "deb " << min_sparse[l][0] << " " << min_sparse[l+1][0] << endl;
    return min(min_sparse[l][lo], min_sparse[r-(1<<lo)+1][lo]);
}
long long find_max(int l, int r) {
    long long lo=logarithm[r-l+1];
    return max(max_sparse[l][lo], max_sparse[r-(1<<lo)+1][lo]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> g;
    for (int i=2; i<=n; i++) {
        logarithm[i]=logarithm[i/2]+1;
        //cout << "log " << i << " " << logarithm[i] << "\n";
    }
    for (int i=1; i<=n; i++) {
        cin >> dif[i] >> cost[i];
        value[i]=g-cost[i];
        //cout << "value " << i << " " << value[i] << "\n";
        ans=max(ans, value[i]);
        min_sparse[i][0]=max_sparse[i][0]=kom_value[i]=kom_value[i-1]+value[i];
        //cout << "kom_value " << i << " " << kom_value[i] << "\n";
    }
    for (int i=1; i<n; i++) {
        gap[i]=dif[i+1]-dif[i];
        //cout << "gap " << i << " " << gap[i] << "\n";
    }
    for (int i=1; i<n; i++) {
        while (mins.size()>0 && gap[i]>=gap[mins.back()]) {
            mins.pop_back();
        }
        if (mins.size()>0) {
            prev_big[i]=mins.back();
        }
        //cout << "prev_big " << i << " " << prev_big[i] << "\n";
        mins.push_back(i);
    }
    mins.clear();
    for (int i=n-1; i>=1; i--) {
        while (mins.size()>0 && gap[i]>=gap[mins.back()]) {
            mins.pop_back();
        }
        next_big[i]=n;
        if (mins.size()>0) {
            next_big[i]=mins.back();
        }
        mins.push_back(i);
    }
    /*
    for (int i=1; i<=n; i++) {
        cout << "next_big " << i << " " << next_big[i] << endl;
    }
    */
    /*
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> max_sparse[i][0];
    }
    */
    for (int j=1; j<20; j++) {
        for (int i=0; i+(1<<j)<=n+1; i++) {
            int s=i+(1<<(j-1));
            max_sparse[i][j]=max(max_sparse[i][j-1], max_sparse[s][j-1]);
            min_sparse[i][j]=min(min_sparse[i][j-1], min_sparse[s][j-1]);
            //cout << i << " " << j << " " << max_sparse[i][j] << endl;
        }
    }
    /*
    int q; cin >> q;
    for (int i=1; i<=q; i++) {
        int l, r; cin >> l >> r;
        cout << find_max(l, r) << endl;
    }
    */
    //cout << "find_min " << find_min(1, 2) << endl;
    //return 0;
    for (int i=1; i<n; i++) {
        long long low=find_min(prev_big[i], i), high=find_max(i+1, next_big[i]);
        //cout << "try " << i << " " << high << " " << low << " " << gap[i] << endl;
        ans=max(ans, high-low-gap[i]*gap[i]);
    }
    cout << ans << "\n";
    return 0;
}