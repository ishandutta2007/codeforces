s=gets.downcase
a=gets.to_i
(0..s.size-1).each do |i|
  c=s[i]
  c=s[i].upcase if s[i].ord<a+97
  print c
end