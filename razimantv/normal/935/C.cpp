#include <iomanip>
#include <iostream>
#include <valarray>

int main() {
  double R;
  std::cin >> R;

  std::valarray<double> p1(2), p2(2);
  std::cin >> p1[0] >> p1[1] >> p2[0] >> p2[1];
  p2 = p2 - p1;

  double s = sqrt((p2*p2).sum());
  if (s >= R) {
  } else if (s < 1e-6) {
    R /= 2;
    p1[0] += R;
  } else {
    p1 += p2 * (1 - R / s) / 2.0;
    R = (R + s) / 2;
  }
  std::cout << std::setprecision(10) << p1[0] << " " << p1[1] << " " << R
            << std::endl;
  return 0;
}