import Control.Monad
import Control.Applicative
import Data.List
import Data.Maybe
import qualified Data.Map as M
import qualified Data.Set as S

readInt :: IO Integer
readInt = read <$> getLine
readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine

f n m s = if s == Just (True, True)
          || (s == Just (True, False) && n-m >= 1)
          || (s == Just (False, True) && n-m >= 1)
          || (s == Just (False, False) && n-m >= 2)
  then "Correct"
  else "Incorrect"

g i c mi ma = case c of
  Just (a, b) -> if mi <= i && i <= ma then Just (a || i == mi, b || i == ma) else Nothing
  Nothing -> Nothing

main :: IO ()
main = do
  [n, m, mi, ma] <- readIntList
  li <- readIntList
  let s = foldr (\i -> \c -> g i c mi ma) (Just (False, False)) li
  putStrLn $ f n m s

 --   case c of
--      Just (a, b) -> if mi <= i && i <= ma then Just (a || i == mi, b || i == ma) else Nothing
--      Nothing -> Nothing