var
 ans:array[1..100] of int64;
  n,a,b,i:longint; teksum:int64;

begin
 readln(n,a,b);
  ans[1]:=1; teksum:=2;
   for i:=2 to n do
    if b<>0
     then
      begin
       ans[i]:=teksum+1;
        if ans[i]>50000 then begin writeln(-1); halt; end;
        teksum:=teksum+ans[i];
       dec(b);
      end
     else
      begin
       if (a<>0) and (i<>2)
        then
         begin
          ans[i]:=ans[i-1]+1;
           if ans[i]>50000 then begin writeln(-1); halt; end;
          dec(a);
         end
        else
         begin
          ans[i]:=1;
         end;
      end;
 if (a=0) and (b=0)
  then
   begin
    for i:=1 to n do write(ans[i],' ');
   end
  else writeln(-1);
end.