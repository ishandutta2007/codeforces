  #include<bits/stdc++.h>
  #define int long long

  using namespace std;
  using pii = pair<int,int>;
  const long long INF = 1e18 + 7;

  int e, s, n, m;

  main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> e >> s >> n >> m;
    map <int, int> gas;
    gas[e] = 3;

    for(int i = 0; i < n; ++i) {
      int t, pos; cin >> t >> pos;
      if(pos <= e) gas[pos] = max(gas[pos], t);
    }

    vector < pii > vec, of[5];
    for(auto &p : gas) vec.push_back(p);
    for(int i = 0; i < vec.size(); ++i) {
      of[vec[i].second].emplace_back(vec[i].first, i);
    }

    vector < pii > risan(vec.size(), {INF, INF});

    auto find_last = [&](int t, int pos) {
      pii answer = {-INF, -INF};
      int oof = pos - s;
      int id = upper_bound(of[t].begin(), of[t].end(), make_pair(oof, INF)) - of[t].begin();
      if(id == of[t].size() || of[t][id].first - oof > s) return answer;
      return of[t][id];
    };


    auto solve = [&](int t, int pos){
      auto answer = make_pair(INF, INF);
      if(pos == e) return make_pair(0LL, 0LL);

      if(t == 1) {
        int id = upper_bound(vec.begin(), vec.end(), make_pair(pos, 4LL)) - vec.begin();
        if(vec[id].first - pos > s) return answer;
        answer = risan[id];
        answer.first += vec[id].first - pos;
        return answer;
      }

      if(t == 2) {
        auto find3 = find_last(3, pos + s);
        if(find3.first > pos) {
          answer = risan[find3.second];
          answer.second += find3.first - pos;
          return answer;
        }

        auto find2 = find_last(2, pos + s);
        if(find2.first > pos) {
          answer = risan[find2.second];
          answer.second += find2.first - pos;
          return answer;
        }

        auto find1 = find_last(1, pos + s);

        if(find1.first > pos) {
          answer = risan[find1.second];
          int dst = find1.first - pos;
          int rem = s - dst;
          answer.first -= rem;
          answer.second += s;
          return answer;
        }
      }

      if(t == 3) {
        auto find3 = find_last(3, pos + s);
        if(find3.first > pos) {
          answer = risan[find3.second];
          return answer;
        }

        auto find2 = find_last(2, pos + s);
        if(find2.first > pos) {
          answer = risan[find2.second];
          int dst = find2.first - pos;
          int rem = s - dst;
          answer.second -= rem;
          return answer;
        }

        auto find1 = find_last(1, pos + s);
        if(find1.first > pos) {
          answer = risan[find1.second];
          int dst = find1.first - pos;
          int rem = s - dst;
          answer.first -= rem;
          return answer;
        }
      }
      return answer;
    };

    for(int i = vec.size() - 1; i >= 0; --i) {
      risan[i] = solve(vec[i].second, vec[i].first);
    }

    for(int i = 0; i < m; ++i) {
      int w; cin >> w;
      auto p = solve(3, w);
      if(p.first >= (long long)1e12) p.first = p.second = -1;
      cout << p.first << " " << p.second << "\n";
    }

    return 0;
  }