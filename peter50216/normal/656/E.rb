#!/usr/bin/env ruby
n = gets.to_i
r = n.times.map { gets.split.map(&:to_i) }

(0...n).each { |k|
  (0...n).each { |i|
    (0...n).each { |j|
      r[i][j]=[r[i][j],r[i][k]+r[k][j]].min
    }
  }
}
ans = 0

(0...n).each { |i|
  (0...n).each { |j|
    ans = [ans, r[i][j]].max
  }
}
puts ans