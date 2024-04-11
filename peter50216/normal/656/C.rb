#!/usr/bin/env ruby

a = gets.chomp
s = 0
def r(x)
  ('a'..'z').to_a.index(x.downcase) || 0
end
a.chars.each do |c|
  v1 = '@' < c
  v2 = '[' > c
  v3 = '`' < c
  v4 = '{' > c
  v12 = v1 && v2
  v34 = v3 && v4
  vm = r(c) + 1
  v12 = v12 ? 1 : 0
  v34 = v34 ? 1 : 0
  v12 *= vm
  v34 *= vm
  v12 -= v34
  s += v12
end
puts s