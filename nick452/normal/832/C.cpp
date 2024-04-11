#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const int kLength = 1000000;

struct People {
  int x;
  int v;
};

double GetTime(const People& people, int ray_position, double ray_speed) {
  double time_to_speed_up = static_cast<double>(ray_position - people.x) / (ray_speed - people.v);
  double distance_to_speed_up = time_to_speed_up * people.v;
  if (distance_to_speed_up >= people.x) {
    return static_cast<double>(people.x) / people.v;
  } else {
    return time_to_speed_up + (people.x - distance_to_speed_up) / (people.v + ray_speed);
  }
}

void GetAllPositions(const vector<People>& peoples, double time_limit, double ray_speed, vector<int>* good_positions) {
  good_positions->resize(kLength + 1);
  for (const auto& people : peoples) {
    if (static_cast<double>(people.x) / people.v <= time_limit) {
      fill(good_positions->begin(), good_positions->end(), 1);
      return;
    }
  }
  auto it = peoples.begin();
  for (int ray_position = 0; ray_position <= kLength; ++ray_position) {
    (*good_positions)[ray_position] = 0;
    while (it != peoples.end() && it->x <= ray_position) {
      if (GetTime(*it, ray_position, ray_speed) <= time_limit) {
        (*good_positions)[ray_position] = 1;
        break;
      }
      ++it;
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  vector<People> peoples_to_left;
  vector<People> peoples_to_right;
  for (int i = 0; i < n; ++i) {
    int x, v, t;
    cin >> x >> v >> t;
    if (t == 1) {
      peoples_to_left.push_back({x, v});
    } else {
      peoples_to_right.push_back({kLength - x, v});
    }
  }
  sort(peoples_to_left.begin(), peoples_to_left.end(), [](const People& p1, const People& p2) {
    return p1.x < p2.x;
  });
  sort(peoples_to_right.begin(), peoples_to_right.end(), [](const People& p1, const People& p2) {
    return p1.x < p2.x;
  });
  double low = 0.0;
  double high = 1e6;
  vector<int> good_positions_to_left;
  vector<int> good_positions_to_right;
  for (int iter = 0; iter < 100; ++iter) {
    double middle = (low + high) / 2.0;
    GetAllPositions(peoples_to_left, middle, s, &good_positions_to_left);
    GetAllPositions(peoples_to_right, middle, s, &good_positions_to_right);
    bool is_possible = false;
    for (int i = 0; i <= kLength; ++i) {
      if (good_positions_to_left[i] && good_positions_to_right[kLength - i]) {
        is_possible = true;
      }
    }
    if (is_possible) {
      high = middle;
    } else {
      low = middle;
    }
  }
  cout << setprecision(20) << (low + high) / 2.0 << endl;
  return 0;
}