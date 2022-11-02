uses math;
 var
     x1,y1,r1,x2,y2,r2,l,answer:extended;


begin

  readln(x1,y1,r1); readln(x2,y2,r2); l:=sqrt(sqr(x1-x2)+sqr(y1-y2));
  if l<=max(r1,r2) then
    begin
      if (l+min(r1,r2))>=max(r1,r2) then
        begin
          answer:=0;
        end
          else
        begin
          answer:=(max(r1,r2)-l-min(r1,r2))/2;
        end;
    end
      else
    begin
      if l<=(r1+r2) then
        begin
          answer:=0;
        end
          else
        begin
          answer:=((l-r1-r2)/2);
        end;
    end;
  writeln(answer:0:9);

end.