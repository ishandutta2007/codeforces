my $n = <STDIN>;
@arr = ();
for (my $i=0; $i < $n; $i++) {
    my $line = <STDIN>;
    chomp $line;
    ($a,$b)= split /:/, $line;
    $a = 60*$a + 1*$b;
    push(@arr, $a);
}

for (my $i=0; $i < $n-1; $i++) {
    for (my $j=$i+1; $j < $n; $j++) {
        if ($arr[$i] > $arr[$j]) {
            ($arr[$i], $arr[$j]) = ($arr[$j], $arr[$i]);
        }
    }
}
my $max = 0;
for (my $i=1; $i < $n; $i++) {
    if ($arr[$i] - $arr[$i-1] - 1 > $max) {
        $max = $arr[$i] - $arr[$i-1] - 1;
    }
}
if (24*60 - $arr[$n-1] + $arr[0] - 1 > $max) {
    $max = 24*60 - $arr[$n-1] + $arr[0] - 1;
}
my $h = int($max / 60);
my $m = $max - $h*60;
if ($h < 10){
    print 0;
}
print $h . ":";
if ($m < 10) {
    print 0;
}
print $m;