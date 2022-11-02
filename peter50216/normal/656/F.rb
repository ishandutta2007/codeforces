#!/usr/bin/env ruby

s = gets.chomp
puts s[1..-1].chars.map{|x| x == '0' ? 9 : x.to_i}.inject(:+) + 1