var
    ans,i,j,w,h:int64;


begin

  readln(w,h); ans:=0; i:=2; j:=2;
   while i<=w do
    begin
     j:=2;
      while j<=h do
       begin
        ans:=ans + (w-i+1)*(h-j+1);
        inc(j,2);
       end;
     i:=i+2;
    end;
  writeln(ans);

end.