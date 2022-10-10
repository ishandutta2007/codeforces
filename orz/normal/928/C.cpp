#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using Tag = std::pair<std::string, int>;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    Tag mp; //    , !

    std::unordered_map<std::string, std::unordered_map<int, std::vector<Tag>>> projects;
    std::unordered_map<std::string, std::pair<int, int>> taken;

    for (int i = 0; i < n; i++) {
        std::string name;
        int version;
        std::cin >> name >> version;
        if (projects.count(name) == 0) {
            projects.insert({name, std::unordered_map<int, std::vector<Tag>>()});
        }
        projects[name].insert({version, std::vector<Tag>()});
        if (i == 0) {
            mp.first = name;
            mp.second = version;
        }

        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::string name1;
            int version1;
            std::cin >> name1 >> version1;
            projects[name][version].emplace_back(name1, version1);
        }

    }

    std::queue<std::string> q;
    std::vector<std::string> names;
    taken.insert(std::make_pair(mp.first, std::make_pair(mp.second, 0)));
    q.push(mp.first);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int dist = taken[node].second;

        for (Tag next : projects[node][taken[node].first]) {
            if (taken.count(next.first) == 0
                || taken[next.first].first < next.second && taken[next.first].second == dist + 1) {
                if (taken.count(next.first) == 0) {
                    taken.insert(std::make_pair(next.first, std::make_pair(next.second, dist + 1)));
                    names.push_back(next.first);
                    q.push(next.first);
                } else {
                    taken[next.first].first = next.second;
                    taken[next.first].second = dist + 1;
                }
            }
        }
    }

    std::cout << names.size() << '\n';
    std::sort(names.begin(), names.end());
    for (const std::string &name : names) {
        std::cout << name << ' ' << taken[name].first << '\n';
    }

    return 0;

}