<?php
$fl =STDIN;//fopen("input.txt","r");
fscanf($fl,"%d\n",$n);
$numbers = explode(" ", trim(fgets($fl)));
$fi = false;
$se = false;
$l = 0;
$ans = 0;
function gcd ($a, $b) {
    return $b ? gcd($b, $a % $b) : $a;
}
sort($numbers);
foreach ($numbers as &$number)
{
    $x = intval($number);
    if($fi) {
        if($se) {
            $ans = gcd($ans, $x-$l);
        }else{
            $ans = $x-$l;
        }
        $se = true;
    }
    $fi = true;
    $l = $x;
}
printf("%d\n", 1+($numbers[$n-1]-$numbers[0])/$ans - $n);
?>