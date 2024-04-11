#include <bits/stdc++.h>

using namespace std;

#define int long long

template <typename T>
inline bool MaxTo(T &u, const T &v) {
  return u < v ? (u = v, true) : false;
}

template <typename T>
inline bool MinTo(T &u, const T &v) {
  return u > v ? (u = v, true) : false;
}

const int INF = 1e18;
const int N = 14;
const int M = 110;

int n, m;
pair<int, int> towers[N];
pair<int, int> quests[M];
int quest_times[M];
int order[M];

int towers_to_tower[1 << N][N];
int towers_to_quest[1 << N][M];

int cur_dp_pos[1 << N];
int dp_tower[1 << N][M]; // min time
int dp_quest[1 << N][M]; // max res

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> towers[i].first >> towers[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> quests[i].first >> quests[i].second >> quest_times[i];
  }

  iota(order + 1, order + m + 1, 1);
  sort(order + 1, order + m + 1, [&](int u, int v) {
    return quest_times[u] < quest_times[v];
  });

  auto Dist = [&](pair<int, int> u, pair<int, int> v) {
    return abs(u.first - v.first) + abs(u.second - v.second);
  };

  auto GetMinDist = [&](int mask, pair<int, int> u) {
    int min_dist = INF;
    for (int j = 0; j < n; j++) {
      if (mask >> j & 1) {
        MinTo(min_dist, Dist(u, towers[j]));
      }
    }
    return min_dist;
  };

  // init min dist
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      towers_to_tower[mask][i] = GetMinDist(mask, towers[i]);
    }
    for (int i = 1; i <= m; i++) {
      towers_to_quest[mask][i] = GetMinDist(mask, quests[i]);
    }
  }

  // init dp
  for (int mask = 0; mask < (1 << n); mask++) {
    fill(dp_tower[mask], dp_tower[mask] + m + 1, INF);
    fill(dp_quest[mask], dp_quest[mask] + m + 1, -INF);
    cur_dp_pos[mask] = 0;
  }

  // spawn in tower positions
  for (int i = 0; i < n; i++) {
    dp_tower[1 << i][0] = 0;
  }

  int ans = 0;

  for (int it = 1; it <= m; it++) {
    int u = order[it];
    int time_limit = quest_times[u];

    // update dp_tower to time_limit
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int &id = cur_dp_pos[mask]; id <= m && dp_tower[mask][id] < time_limit; id++) {
        // move to tower
        for (int i = 0; i < n; i++) {
          if (mask >> i & 1) continue;
          MinTo(dp_tower[mask ^ (1 << i)][id], dp_tower[mask][id] + towers_to_tower[mask][i]);
        }
        // move to quests
        for (int it1 = 1; it1 <= m; it1++) {
          int v = order[it1];
          if (dp_tower[mask][id] + towers_to_quest[mask][v] <= quest_times[v]) {
            MaxTo(dp_quest[mask][it1], id + 1);
          }
        }
      }
    }

    // update dp_quest
    
    // spawn in quest position
    MaxTo(dp_quest[0][it], 1ll);

    for (int mask = 0; mask < (1 << n); mask++) {
      int res = dp_quest[mask][it];
      if (res < 0) continue;
      MaxTo(ans, res);
      // move to tower
      for (int i = 0; i < n; i++) {
        if (mask >> i & 1) continue;
        int move_time = min(Dist(quests[u], towers[i]), towers_to_tower[mask][i]);
        MinTo(dp_tower[mask ^ (1 << i)][res], quest_times[u] + move_time);
      }
      // move to quest
      for (int it1 = it + 1; it1 <= m; it1++) {
        int v = order[it1];
        int move_time = min(Dist(quests[u], quests[v]), towers_to_quest[mask][v]);
        if (quest_times[u] + move_time <= quest_times[v]) {
          MaxTo(dp_quest[mask][it1], res + 1);
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}