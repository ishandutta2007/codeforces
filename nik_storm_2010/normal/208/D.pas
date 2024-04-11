var
    ar:array[1..50] of int64;
     a,b,c,d,e,sum,a1,a2,a3,a4,a5,k:int64;
      i,n:longint;


begin

  readln(n);
   for i:=1 to n do read(ar[i]);
   readln; sum:=0;
  readln(a,b,c,d,e);

  for i:=1 to n do
   begin
    sum:=sum+ar[i];
     while sum>=a do
      begin
       if sum>=e then begin k:=sum div e; inc(a5,k); sum:=sum-e*k; end else
        if sum>=d then begin k:=sum div d; inc(a4,k); sum:=sum-d*k; end else
         if sum>=c then begin k:=sum div c; inc(a3,k); sum:=sum-c*k; end else
        if sum>=b then begin k:=sum div b; inc(a2,k); sum:=sum-b*k; end
         else
          begin
           k:=sum div a;
            inc(a1,k);
           sum:=sum-a*k;
          end;
      end;
   end;
  writeln(a1,' ',a2,' ',a3,' ',a4,' ',a5); writeln(sum);

end.