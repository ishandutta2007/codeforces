var
    koef,can,middle,must,left,right: extended;
    a: array[1..10000] of longint;
    n,i,k: longint;



Begin

  readln(n,k);
   for i:=1 to n do
    read(a[i]);

  koef:=1-k/100;
   left:=0;
    right:=1000;
     while right - left > 0.0000001 do
      begin

        middle:=(right+left) / 2;
         can:=0;
          must:=0;
           for i:=1 to n do
            if a[i] > middle
             then can:=can+a[i]-middle
             else must:=must+middle-a[i];

        if can*koef-must>=0 then left:=middle
                            else right:=middle;

      end;

  writeln((right+left)/2:0:7);

End.